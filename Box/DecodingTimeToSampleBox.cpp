//
// Created by kris on 2022/5/6.
//

#include "DecodingTimeToSampleBox.h"

DecodingTimeToSampleBox::DecodingTimeToSampleBox(uint32_t size, uint32_t type, uint32_t start_pos) : FullBox(size, type,
                                                                                                            start_pos) {}

DecodingTimeToSampleBox::~DecodingTimeToSampleBox() {

}

void DecodingTimeToSampleBox::Parse(struct Parser *parser, uint32_t start_pos) {
    FullBox::Parse(parser, start_pos);

    FileReader *file_reader = parser->file_reader;

    number_of_entries = file_reader->Read32();
    time_to_sample_item_table = std::vector<TimeToSampleItem>(number_of_entries);

    for (size_t i = 0; i < time_to_sample_item_table.size(); i++) {
        TimeToSampleItem item;

        item.sample_count = file_reader->Read32();
        item.sample_duration = file_reader->Read32();

        time_to_sample_item_table[i] = item;
    }

    Stream *s = parser->streams[parser->stream_num - 1];
    s->stts_count = number_of_entries;
    s->stts_data = time_to_sample_item_table;
}
