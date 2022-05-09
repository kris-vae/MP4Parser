//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_SYNCSAMPLEBOX_H
#define MP4PARSER_SYNCSAMPLEBOX_H

#include "FullBox.h"

class SyncSampleBox : public FullBox {
    uint32_t number_of_entries;
    std::vector<uint32_t> sync_sample_item_table;

public:
    SyncSampleBox(uint32_t size, uint32_t type, uint32_t start_pos);
    virtual ~SyncSampleBox();
    void Parse(struct Parser *parser, uint32_t start_pos) override;
};


#endif //MP4PARSER_SYNCSAMPLEBOX_H
