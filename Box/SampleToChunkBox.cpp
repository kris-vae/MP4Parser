//
// Created by kris on 2022/5/6.
//

#include "SampleToChunkBox.h"

SampleToChunkBox::SampleToChunkBox(uint32_t size, uint32_t type, uint32_t start_pos) : FullBox(size, type, start_pos) {}

SampleToChunkBox::~SampleToChunkBox() {
}

void SampleToChunkBox::Parse(struct Parser *parser, uint32_t start_pos) {
    FullBox::Parse(parser, start_pos);

    FileReader *file_reader = parser->file_reader;
    number_of_entries = file_reader->Read32();
    sample_to_chunk_item_table = std::vector<SampleToChunkItem>(number_of_entries);

    for (size_t i = 0; i < sample_to_chunk_item_table.size(); i++) {
        SampleToChunkItem item;

        item.first_chunk = file_reader->Read32();
        item.samples_per_chunk = file_reader->Read32();
        item.sample_description_id = file_reader->Read32();

        sample_to_chunk_item_table[i] = item;
    }

    Stream *s = parser->streams[parser->stream_num-1];

    s->stsc_count = number_of_entries;
    s->stsc_data = sample_to_chunk_item_table;
}
