//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_SAMPLEDESCRIPTIONBOX_H
#define MP4PARSER_SAMPLEDESCRIPTIONBOX_H

#include "FullBox.h"

typedef struct SampleDescriptionItem {
    uint32_t size;
    std::string data_format;
    std::vector<uint8_t> reserved;
    uint16_t data_reference_index;
}SampleDescriptionItem;

class SampleDescriptionBox : public FullBox {
public:
    uint32_t number_of_entries;
    std::vector<SampleDescriptionItem> sample_description_item_table;

public:
    SampleDescriptionBox(uint32_t size, uint32_t type, uint64_t start_pos);
    virtual ~SampleDescriptionBox();
    void Parse(struct Parser *parser, uint64_t start_pos) override;
};


#endif //MP4PARSER_SAMPLEDESCRIPTIONBOX_H
