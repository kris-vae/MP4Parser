//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_DECODINGTIMETOSAMPLEBOX_H
#define MP4PARSER_DECODINGTIMETOSAMPLEBOX_H

#include "FullBox.h"

class DecodingTimeToSampleBox : public FullBox {
public:
    uint32_t number_of_entries;
    std::vector<TimeToSampleItem> time_to_sample_item_table;

public:
    DecodingTimeToSampleBox(uint32_t size, uint32_t type, uint64_t start_pos);

    virtual ~DecodingTimeToSampleBox();

    void Parse(struct Parser *parser, uint64_t start_pos) override;
};


#endif //MP4PARSER_DECODINGTIMETOSAMPLEBOX_H
