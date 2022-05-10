//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_FULLBOX_H
#define MP4PARSER_FULLBOX_H

#include "Box.h"

class FullBox : public Box{
public:
    uint8_t version;
    uint32_t flags;     //lower 24 bits valid

public:
    FullBox(uint32_t size, uint32_t type, uint32_t start_pos);
    virtual ~FullBox();

    virtual void Parse(struct Parser *parser, uint32_t start_pos) override;
};


#endif //MP4PARSER_FULLBOX_H
