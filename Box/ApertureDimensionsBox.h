//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_APERTUREDIMENSIONSBOX_H
#define MP4PARSER_APERTUREDIMENSIONSBOX_H

#include "FullBox.h"

class ApertureDimensionsBox : public FullBox {
public:
    uint32_t width;
    uint32_t height;

public:
    ApertureDimensionsBox(uint32_t size, uint32_t type, uint64_t start_pos);
    virtual ~ApertureDimensionsBox();
    void Parse(struct Parser *parser, uint64_t start_pos) override;
};


#endif //MP4PARSER_APERTUREDIMENSIONSBOX_H
