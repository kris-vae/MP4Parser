//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_VIDEOMEDIAHEADERBOX_H
#define MP4PARSER_VIDEOMEDIAHEADERBOX_H

#include "FullBox.h"

class VideoMediaHeaderBox : public FullBox {
public:
    uint16_t graphics_mode;
    uint16_t red;
    uint16_t green;
    uint16_t blue;

public:
    VideoMediaHeaderBox(uint32_t size, uint32_t type, uint32_t start_pos);
    virtual ~VideoMediaHeaderBox();
    void Parse(struct Parser *parser, uint32_t start_pos) override;
};


#endif //MP4PARSER_VIDEOMEDIAHEADERBOX_H
