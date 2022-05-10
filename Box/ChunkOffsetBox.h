//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_CHUNKOFFSETBOX_H
#define MP4PARSER_CHUNKOFFSETBOX_H

#include "FullBox.h"

class ChunkOffsetBox : public FullBox {
public:
    uint32_t number_of_entries;
    std::vector<uint32_t> chunk_offset_item_table;

public:
    ChunkOffsetBox(uint32_t size, uint32_t type, uint64_t start_pos);
    virtual ~ChunkOffsetBox();
    void Parse(struct Parser *parser, uint64_t start_pos) override;
};


#endif //MP4PARSER_CHUNKOFFSETBOX_H
