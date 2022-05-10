//
// Created by kris on 2022/5/6.
//

#include "CompositionTimeToSampleBox.h"

CompositionTimeToSampleBox::CompositionTimeToSampleBox(uint32_t size, uint32_t type, uint64_t start_pos) : FullBox(size,
                                                                                                                  type,
                                                                                                                  start_pos) {}

CompositionTimeToSampleBox::~CompositionTimeToSampleBox() {

}

void CompositionTimeToSampleBox::Parse(struct Parser *parser, uint64_t start_pos) {
    FullBox::Parse(parser, start_pos);

    FileReader *file_reader = parser->file_reader;

    number_of_entries = file_reader->Read32();
    composition_offset_item_table = std::vector<CompositionOffsetItem>(number_of_entries);

    for (size_t i = 0; i < composition_offset_item_table.size(); i++) {
        CompositionOffsetItem item;

        item.sample_count = file_reader->Read32();
        item.sample_offset = file_reader->Read32();

        composition_offset_item_table[i] = item;
    }

    Stream *s = parser->streams[parser->stream_num-1];
    s->ctts_count = number_of_entries;
    s->ctts_data = composition_offset_item_table;
}
