//
// Created by kris on 2022/5/8.
//

#ifndef MP4PARSER_DISPLAY_H
#define MP4PARSER_DISPLAY_H

#include <QTreeWidget>
#include <QTextEdit>
#include <QtGlobal>
#include "Parser.h"
#include "Box/Box.h"

class Display {
public:
    Display();
    virtual ~Display();

public:
    void ShowBox(QTreeWidget *root, QTextEdit *edit, Parser *parser);
private:
    void CreateWidgetTree(QTreeWidgetItem *tree_item, Box *box);
    static std::string  DurationFormatter(uint64_t seconds);
};


#endif //MP4PARSER_DISPLAY_H
