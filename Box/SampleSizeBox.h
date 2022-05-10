//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_SAMPLESIZEBOX_H
#define MP4PARSER_SAMPLESIZEBOX_H

#include "FullBox.h"

class SampleSizeBox : public FullBox {
public:
    uint32_t sample_size;
    uint32_t number_of_entries;
    std::vector<uint32_t> sample_size_item_table;

public:
    SampleSizeBox(uint32_t size, uint32_t type, uint64_t start_pos);
    virtual ~SampleSizeBox();
    void Parse(struct Parser *parser, uint64_t start_pos) override;
};


#endif //MP4PARSER_SAMPLESIZEBOX_H
