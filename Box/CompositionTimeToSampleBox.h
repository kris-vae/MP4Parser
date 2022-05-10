//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_COMPOSITIONTIMETOSAMPLEBOX_H
#define MP4PARSER_COMPOSITIONTIMETOSAMPLEBOX_H

#include "FullBox.h"

class CompositionTimeToSampleBox : public FullBox{
public:
    uint32_t number_of_entries;
    std::vector<CompositionOffsetItem> composition_offset_item_table;

public:
    CompositionTimeToSampleBox(uint32_t size, uint32_t type, uint32_t start_pos);
    virtual ~CompositionTimeToSampleBox();
    void Parse(struct Parser *parser, uint32_t start_pos) override;
};


#endif //MP4PARSER_COMPOSITIONTIMETOSAMPLEBOX_H
