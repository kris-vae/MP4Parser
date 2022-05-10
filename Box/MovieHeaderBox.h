//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_MOVIEHEADERBOX_H
#define MP4PARSER_MOVIEHEADERBOX_H

#include "FullBox.h"

class MovieHeaderBox : public FullBox {
public:
    uint32_t creation_time;
    std::string creation_time_formatter;
    uint32_t modification_time;
    std::string modification_time_formatter;

    uint32_t time_scale;
    uint32_t duration;

    uint32_t preferred_rate;
    std::string preferred_rate_formatter;

    uint16_t preferred_volume;
    std::string preferred_volume_formatter;

    std::vector<uint8_t> reserved;
    std::vector<std::vector<uint32_t>> matrix;

    uint32_t preview_time;
    std::string preview_time_formatter;
    uint32_t preview_duration;

    uint32_t poster_time;
    std::string poster_time_formatter;

    uint32_t selection_time;
    std::string selection_time_formatter;
    uint32_t selection_duration;

    uint32_t current_time;
    std::string current_time_formatter;

    uint32_t next_track_id;

public:
    MovieHeaderBox(uint32_t size, uint32_t type, uint64_t start_pos);
    virtual ~MovieHeaderBox();
    void Parse(struct Parser *parser, uint64_t start_pos) override;
};


#endif //MP4PARSER_MOVIEHEADERBOX_H
