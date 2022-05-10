//
// Created by kris on 2022/5/6.
//

#include "SampleSizeBox.h"

SampleSizeBox::SampleSizeBox(uint32_t size, uint32_t type, uint32_t start_pos) : FullBox(size, type, start_pos) {}

SampleSizeBox::~SampleSizeBox() {

}

void SampleSizeBox::Parse(struct Parser *parser, uint32_t start_pos) {
    FullBox::Parse(parser, start_pos);

    sample_size = parser->file_reader->Read32();

    if (sample_size == 0) {
        number_of_entries = parser->file_reader->Read32();
        sample_size_item_table = std::vector<uint32_t>(number_of_entries);

        for (size_t i = 0; i < sample_size_item_table.size(); i++)
            sample_size_item_table[i] = parser->file_reader->Read32();

        Stream *s = parser->streams[parser->stream_num-1];
        s->stsz_count = number_of_entries;
        s->stsz_data = sample_size_item_table;
    }
}
