//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_BOX_H
#define MP4PARSER_BOX_H

#include <stdint.h>
#include <string>
#include <sstream>
#include <vector>
#include "../Parser.h"
#include "../Define.h"

class Box {
public:
    uint32_t size;
    uint32_t type;
    std::string name;
    uint32_t start_pos;

    Box *child_head;
    Box *child_trail;
    Box *next;

public:
    Box(uint32_t size, uint32_t type, uint32_t start_pos);
    virtual ~Box();

public:
    virtual void Parse(class Parser *parser, uint32_t start_pos);
    virtual std::string Description();

public:
    void AddChild(Box *child);
    std::string ConvertToString(uint32_t bits);
    std::string ConvertToFormatterTime(uint32_t time);
};

#endif //MP4PARSER_BOX_H
