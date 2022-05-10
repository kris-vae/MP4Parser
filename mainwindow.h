//
// Created by kris on 2022/5/8.
//

#ifndef MP4PARSER_MAINWINDOW_H
#define MP4PARSER_MAINWINDOW_H

#include <QMainWindow>
#include <qtreewidget.h>
#include "FileReader.h"
#include "Parser.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    class FileReader *file_reader;
    class Parser *parser;

    uint32_t sample_count;
    uint32_t current_sample_num;

    bool is_show_video_sample;

private:
    void DisplayHexFromReader(class FileReader* file_reader, uint64_t start_pos, uint32_t len);
    void DisplayHex(uint8_t *buffer, uint32_t len);
    void SetHighlight(uint64_t start_pos, uint32_t len);

    void ResetSampleInfo();
    Box *GetItemBox(QTreeWidgetItem *item);
    void Clear();
    class Stream *ShowingStream();
    void ShowSample(Stream *s, uint32_t index);
private slots:
    void on_openButton_clicked();
    void on_structTree_itemClicked(QTreeWidgetItem * item, int column);

    void on_homeButton_clicked();
    void on_endButton_clicked();
    void on_prevButton_clicked();
    void on_nextButton_clicked();

    void on_radioVideo_clicked();
    void on_radioAudio_clicked();

    void on_tabWidget_currentChanged(int index);
    void on_lineEditSample_returnPressed();

private:
    Ui::MainWindow *ui;
};


#endif //MP4PARSER_MAINWINDOW_H
