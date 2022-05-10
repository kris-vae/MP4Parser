//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_COMPOSITIONTODECODEBOX_H
#define MP4PARSER_COMPOSITIONTODECODEBOX_H

#include "FullBox.h"

class CompositionToDecodeBox : public FullBox {
public:
    uint32_t shift;
    uint32_t least_display_offset;
    uint32_t greatest_display_offset;
    uint32_t display_start_time;
    std::string display_start_time_formatter;
    uint32_t display_end_time;
    std::string display_end_time_formatter;

public:
    CompositionToDecodeBox(uint32_t size, uint32_t type, uint64_t start_pos);
    virtual ~CompositionToDecodeBox();
    void Parse(struct Parser *parser, uint64_t start_pos) override;
};


#endif //MP4PARSER_COMPOSITIONTODECODEBOX_H
