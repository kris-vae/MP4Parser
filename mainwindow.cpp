//
// Created by kris on 2022/5/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <qtextedit.h>
#include <qtextcursor.h>
#include <qfiledialog.h>
#include <QtGlobal>
#include "mainwindow.h"
#include "ui_MainWindow.h"
#include "Display.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {

    file_reader = nullptr;
    parser = nullptr;
    ui->setupUi(this);
#ifdef Q_OS_DARWIN
    QFont font("SimSun",14,QFont::Normal);
    ui->hexView->setFont(font);
#endif

    ResetSampleInfo();
    ui->tabWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_openButton_clicked() {
    QFileDialog *dlg = new QFileDialog(this);
    if (dlg->exec() == QFileDialog::Accepted) {
        QStringList files = dlg->selectedFiles();
        QString file_name = files.at(0);
        this->ui->filePathEdit->setText(file_name);

        if (parser == nullptr) delete parser;
        if (file_reader == nullptr) delete file_reader;

        file_reader = new FileReader();
        parser = new Parser(file_reader);

        ResetSampleInfo();
        ui->tabWidget->setCurrentIndex(0);
        ui->hexView->clear();

        parser->Parse(file_name.toLocal8Bit().data());
        Display display;
        display.ShowBox(ui->structTree, ui->baseInfoTextEdit, parser);
        DisplayHexFromReader(file_reader, 0, 1024);
    }
}

void MainWindow::ResetSampleInfo() {
    is_show_video_sample = true;
    sample_count = 0;
    current_sample_num = 0;

    ui->lineEditSample->setText("0/0");
    ui->radioAudio->setChecked(false);
    ui->radioVideo->setChecked(true);
    ui->textEditSampleInfo->clear();
}

uint32_t Min(uint32_t a, uint32_t b) {
    return a < b ? a : b;
}

uint32_t Max(uint32_t a, uint32_t b) {
    return a > b ? a : b;
}

char GetPrintableChar(unsigned char c) {
    if (c >= 128 || c <= 32)
        return '.';
    else
        return c;
}

void MainWindow::DisplayHex(uint8_t *buffer, uint32_t len) {
    Q_ASSERT(buffer && len >= 0);

    len = Min(len, 4096);
    uint32_t rows = len / 16 + (len % 16 == 0 ? 0 : 1);
    ui->hexView->clear();
    uint32_t index = 0;
    for (uint32_t i = 0; i < rows; i++) {
        QString str;
        QString str1;
        QString str2;

        uint32_t num = 16;

        if ((i + 1) * 16 > len) num = len - i * 16;

        for (uint32_t j = 0; j < num; j++) {
            str1 += QString::asprintf("%02X%c", buffer[index], ' ');
            str2 += QString::asprintf("%c", GetPrintableChar(buffer[index]));
            index++;
        }

        if (num < 16) {
            for (uint32_t k = 0; k < 16 - num; k++) str1 += "  ";
        }

        str = str1 + "  " + str2;
        ui->hexView->append(str);
    }
}

void MainWindow::DisplayHexFromReader(struct FileReader *reader, uint64_t start_pos, uint32_t len) {
    uint8_t *buffer = new uint8_t[len];
    file_reader->Seek(start_pos);
    file_reader->ReadToBuffer(buffer, len);
    DisplayHex(buffer, len);
    delete []buffer;
    SetHighlight(0, 0);
}

void MainWindow::SetHighlight(uint64_t start_pos, uint32_t len) {
    QTextEdit *edit = ui->hexView;
    QTextCursor cursor = edit->textCursor();

    uint32_t start_text_pos= start_pos * 3;
    uint32_t len_of_text = len * 3 - 1;

    cursor.setPosition(start_text_pos);
    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor, len_of_text);

    QTextEdit::ExtraSelection selection;
    selection.cursor = cursor;
    QColor line_color = QColor(Qt::yellow).lighter(160);
    selection.format.setBackground(line_color);
    QList<QTextEdit::ExtraSelection> extra_selections;
    extra_selections.append(selection);
    edit->setExtraSelections(extra_selections);

    cursor.clearSelection();
    cursor.setPosition(start_text_pos);
    edit->setTextCursor(cursor);
}

void MainWindow::on_homeButton_clicked() {
    Stream *s = ShowingStream();
    if (s != nullptr) ShowSample(s, 1);
}

void MainWindow::on_endButton_clicked() {
    Stream *s = ShowingStream();
    if (s != nullptr) ShowSample(s, s->stsz_count - 1);
}

void MainWindow::on_prevButton_clicked() {
    Stream *s = ShowingStream();
    if (s != nullptr) ShowSample(s, current_sample_num - 1);
}

void MainWindow::on_nextButton_clicked() {
    Stream *s = ShowingStream();
    if (s != nullptr) ShowSample(s, current_sample_num + 1);
}

void MainWindow::on_radioVideo_clicked() {
    is_show_video_sample = true;
    on_homeButton_clicked();
}

void MainWindow::on_radioAudio_clicked() {
   is_show_video_sample = false;
   on_homeButton_clicked();
}

void MainWindow::on_tabWidget_currentChanged(int index) {
    if (index == 1 && current_sample_num == 0)
        on_homeButton_clicked();
}

void MainWindow::on_lineEditSample_returnPressed() {
    Stream *s = ShowingStream();
    if (s == nullptr) return;

    QString sample_index = ui->lineEditSample->text();
    QString index_str = sample_index;

    if (sample_index.contains('/')) {
        int left = sample_index.indexOf('/');
        index_str = sample_index.left(left);
    }

    int index = index_str.toInt();
    if (index <= 0) index = 1;
    else if(index > sample_count) index = sample_count;

    ShowSample(s, index);
}

Box *MainWindow::GetItemBox(QTreeWidgetItem *item) {
    Box *box = nullptr;
    QVariant value = item->data(0, Qt::UserRole);
    box = (Box *)value.value<void *>();
    return box;
}

void MainWindow::Clear() {
    QTreeWidget *tree = ui->structTree;
    tree->clear();
    ui->hexView->clear();
}

void MainWindow::on_structTree_itemClicked(QTreeWidgetItem *item, int column) {
    ui->hexView->clear();
    Box *box = GetItemBox(item);
    if (box == nullptr) return ;

    ui->baseInfoTextEdit->setText(QString::fromStdString(box->Description()));
    DisplayHexFromReader(file_reader, box->start_pos, box->size);
}

class Stream *MainWindow::ShowingStream() {

    if (parser == nullptr)
        return nullptr;

    Stream *s = nullptr;
    if (is_show_video_sample)
        s = parser->VideoStream();
    else
        s = parser->AudioStream();

    return s;
}

void MainWindow::ShowSample(Stream *s, uint32_t index) {
    sample_count = s->stsz_count;

    if (index > sample_count)
        index = sample_count;
    if (index <= 0)
        index = 1;

    current_sample_num = index;
    char tmp[128];
    sprintf(tmp, "%d/%d", current_sample_num, sample_count);
    ui->lineEditSample->setText(tmp);

    ui->hexView->clear();
    uint32_t start = s->sample_position[index - 1];
    uint32_t len = s->stsz_data[index - 1];

    DisplayHexFromReader(file_reader, start, len);

    char sample_info[1024];
    sprintf(sample_info, "Position = %d\nLength = %d (0x%02X)\n", start, len, len);
    ui->textEditSampleInfo->setText(sample_info);
}

