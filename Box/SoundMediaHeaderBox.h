//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_SOUNDMEDIAHEADERBOX_H
#define MP4PARSER_SOUNDMEDIAHEADERBOX_H

#include "FullBox.h"

class SoundMediaHeaderBox : public FullBox {
public:
    uint16_t balance;

public:
    SoundMediaHeaderBox(uint32_t size, uint32_t type, uint64_t start_pos);

    virtual ~SoundMediaHeaderBox();

    void Parse(struct Parser *parser, uint64_t start_pos) override;
};


#endif //MP4PARSER_SOUNDMEDIAHEADERBOX_H
