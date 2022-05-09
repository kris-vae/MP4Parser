//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_PARSER_H
#define MP4PARSER_PARSER_H

#include <iostream>
#include "FileReader.h"
#include "FourCC.h"
#include "Box/Box.h"
#include "Define.h"

class Box;
class Parser;

class Parser {
public:
    FileReader *file_reader;
    Box *root;
    std::string file_path;

    uint64_t duration;
    uint32_t time_scale;
    uint32_t width;
    uint32_t height;

    uint32_t stream_num;
    Stream *streams[MAX_STREAM_COUNT];

public:
    Parser();
    Parser(FileReader *fileReader);
    virtual ~Parser();

public:
    void init();
    Box *ReadBox(uint32_t start_pos, bool is_item_box = false);
    Box *CreateBox(uint32_t size, uint32_t type, uint32_t start_pos, bool is_item_box = false);
    int Parse(const char *path);
    Box *ParseResult();
    bool isMOVFile();
    Stream *AddStream();
    Stream *VideoStream();
    Stream *AudioStream();
    void SamplePosition(class Stream *s);
};


#endif //MP4PARSER_PARSER_H
