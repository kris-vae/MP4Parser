//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_FREESPACEBOX_H
#define MP4PARSER_FREESPACEBOX_H

#include "Box.h"

class FreeSpaceBox : public Box{
public:
    FreeSpaceBox(uint32_t size, uint32_t type, uint64_t start_pos);
    virtual ~FreeSpaceBox();
    virtual void Parse(struct Parser *parser, uint64_t start_pos) override;

public:
    std::vector<uint8_t> data;
};


#endif //MP4PARSER_FREESPACEBOX_H
