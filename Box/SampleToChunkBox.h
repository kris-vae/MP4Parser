//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_SAMPLETOCHUNKBOX_H
#define MP4PARSER_SAMPLETOCHUNKBOX_H

#include "FullBox.h"

class SampleToChunkBox : public FullBox {
public:
    uint32_t number_of_entries;
    std::vector<SampleToChunkItem> sample_to_chunk_item_table;

public:
    SampleToChunkBox(uint32_t size, uint32_t type, uint64_t start_pos);

    virtual ~SampleToChunkBox();

    void Parse(struct Parser *parser, uint64_t start_pos) override;
};


#endif //MP4PARSER_SAMPLETOCHUNKBOX_H
