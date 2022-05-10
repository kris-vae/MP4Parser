//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_TRACKHEADERBOX_H
#define MP4PARSER_TRACKHEADERBOX_H

#include "FullBox.h"

class TrackHeaderBox : public FullBox {
public:
    uint32_t creation_time;
    std::string creation_time_formatter;

    uint32_t modification_time;
    std::string modification_time_formatter;

    uint32_t track_id;
    uint32_t duration;

    uint16_t layer;
    uint16_t alternate_group;
    uint16_t volume;

    std::vector<std::vector<uint32_t>> matrix;
    uint32_t track_width;
    uint32_t track_height;

public:
    TrackHeaderBox(uint32_t size, uint32_t type, uint64_t start_pos);
    virtual ~TrackHeaderBox();
    void Parse(struct Parser *parser, uint64_t start_pos) override;
};


#endif //MP4PARSER_TRACKHEADERBOX_H
