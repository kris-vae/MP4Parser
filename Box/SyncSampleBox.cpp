//
// Created by kris on 2022/5/6.
//

#include "SyncSampleBox.h"

SyncSampleBox::SyncSampleBox(uint32_t size, uint32_t type, uint64_t start_pos) : FullBox(size, type, start_pos) {}

SyncSampleBox::~SyncSampleBox() {

}

void SyncSampleBox::Parse(struct Parser *parser, uint64_t start_pos) {
    FullBox::Parse(parser, start_pos);

    number_of_entries = parser->file_reader->Read32();
    sync_sample_item_table = std::vector<uint32_t>(number_of_entries);

    for (size_t i = 0; i < sync_sample_item_table.size(); i++)
        sync_sample_item_table[i] = parser->file_reader->Read32();

    Stream* s = parser->streams[parser->stream_num-1];
    s->stss_count = number_of_entries;
    s->stss_data = sync_sample_item_table;
}
