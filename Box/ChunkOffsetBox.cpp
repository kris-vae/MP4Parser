//
// Created by kris on 2022/5/6.
//

#include "ChunkOffsetBox.h"

ChunkOffsetBox::ChunkOffsetBox(uint32_t size, uint32_t type, uint32_t start_pos) : FullBox(size, type, start_pos) {}

ChunkOffsetBox::~ChunkOffsetBox() {

}

void ChunkOffsetBox::Parse(struct Parser *parser, uint32_t start_pos) {
    FullBox::Parse(parser, start_pos);

    number_of_entries = parser->file_reader->Read32();
    chunk_offset_item_table = std::vector<uint32_t>(number_of_entries);

    for (size_t i = 0; i < chunk_offset_item_table.size(); i++)
        chunk_offset_item_table[i] = parser->file_reader->Read32();

    Stream *s = parser->streams[parser->stream_num-1];
    s->stco_count = number_of_entries;
    s->stco_data = chunk_offset_item_table;
}
