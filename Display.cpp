//
// Created by kris on 2022/5/8.
//

#include "Display.h"

Display::Display() {}

Display::~Display() {

}

void Display::CreateWidgetTree(QTreeWidgetItem *root, Box *box) {
    if (box == nullptr) return;

    QTreeWidgetItem *node = new QTreeWidgetItem(QStringList(QString::fromStdString(box->name)));
    QVariant value = QVariant::fromValue((void *)box);
    node->setData(0, Qt::UserRole, value);
    root->addChild(node);

    if (box->child_head != nullptr) CreateWidgetTree(node, box->child_head);
    if (box->next != nullptr) CreateWidgetTree(root, box->next);
}

std::string HandleType(uint32_t type) {
    if (type == HANDLER_VIDEO)
        return "Video";
    else if(type == HANDLER_AUDIO)
        return "Audio";
    else if(type == HANDLER_HINT)
        return "Hint";
    else if(type == HANDLER_META)
        return "Meta";
    else
        return "Unknow";
}
void HandleStreamInfo(const Parser *parser, QString &info) {
    for (int i = 0; i < parser->stream_num; i++) {
        Stream *s = parser->streams[i];

        if (s->type == HANDLER_VIDEO) {
            info += QString::asprintf("stream %d:%s\n"
                                      "tkhd_width = %d\n"
                                      "tkhd_height=%d\n"
                                      "language = %s\n"
                                      "width = %d\n"
                                      "height = %d\n"
                                      "codec = %s\n",
                                      i+1, HandleType(s->type).c_str(),
                                      s->tkhd_width,
                                      s->tkhd_height,
                                      s->language.c_str(),
                                      s->width,
                                      s->height,
                                      s->codec_name);
        }

        if (s->type == HANDLER_AUDIO) {
            info += QString::asprintf("stream %d:%s\n"
                                      "language = %s\n"
                                      "channel_count = %d\n"
                                      "sample_size = %d\n"
                                      "sample_rate = %d\n"
                                      "codec = %s\n",
                                      i, HandleType(s->type).c_str(),
                                      s->language.c_str(),
                                      s->channel_count,
                                      s->sample_size,
                                      s->sample_rate,
                                      s->codec_name);
        }

        info += QString::fromStdString("\n");
        info += QString::asprintf("sync frame count = %d\n"
                                  "ctts count = %d\n"
                                  "chunk count = %d\n"
                                  "SampleToChunk count = %d\n"
                                  "Sample count = %d\n",
                                  s->stss_count,
                                  s->ctts_count,
                                  s->stco_count,
                                  s->stsc_count,
                                  s->stsz_count
        );

        info += QString::fromStdString("\n");

        if (s->stts_count > 0) {
            info += QString::asprintf("stts_count = %d\n", s->stts_count);
            for(int j = 0; j < s->stts_count; j++)
            {
                info += QString::asprintf("sample_count = %d, duration = %d\n", s->stts_data[j].sample_count, s->stts_data[j].sample_duration);
            }
        }

        info += QString::fromStdString("\n");
    }
}

void Display::ShowBox(QTreeWidget *tree, QTextEdit *edit, Parser *parser) {
    tree->clear();

    QTreeWidgetItem *root = new QTreeWidgetItem(QStringList(QString::fromStdString("root")));
    tree->addTopLevelItem(root);
    root->setExpanded(true);

    Box *result = parser->ParseResult();
    if (result == nullptr) return ;

    CreateWidgetTree(root, result->child_head);

    QString info;
    info += QString::asprintf("duration = %.02f\n", (float)(parser->duration / parser->time_scale));

    HandleStreamInfo(parser, info);
    edit->append(info);
    QTextCursor cursor = edit->textCursor();
    cursor.setPosition(1);
    edit->setTextCursor(cursor);
}
