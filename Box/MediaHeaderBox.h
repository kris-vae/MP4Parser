//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_MEDIAHEADERBOX_H
#define MP4PARSER_MEDIAHEADERBOX_H

#include "FullBox.h"

class MediaHeaderBox : public FullBox {
public:
    uint32_t creation_time;
    std::string creation_time_formatter;
    uint32_t  modification_time;
    std::string modification_time_formatter;
    uint32_t time_scale;
    uint32_t duration;
    uint16_t language;
    uint16_t quality;

public:
    MediaHeaderBox(uint32_t size, uint32_t type, uint32_t start_pos);

    virtual ~MediaHeaderBox();

    void Parse(struct Parser *parser, uint32_t start_pos) override;
};


#endif //MP4PARSER_MEDIAHEADERBOX_H
