//
// Created by kris on 2022/5/6.
//

#include "TrackHeaderBox.h"

TrackHeaderBox::TrackHeaderBox(uint32_t size, uint32_t type, uint64_t start_pos) : FullBox(size, type, start_pos) {
    matrix = std::vector<std::vector<uint32_t>>(3, std::vector<uint32_t>(3));
}

TrackHeaderBox::~TrackHeaderBox() {

}

void TrackHeaderBox::Parse(struct Parser *parser, uint64_t start_pos) {
    FullBox::Parse(parser, start_pos);

    FileReader *file_reader = parser->file_reader;

    creation_time = file_reader->Read32();
    creation_time_formatter = ConvertToFormatterTime(creation_time);

    modification_time = file_reader->Read32();
    modification_time_formatter = ConvertToFormatterTime(modification_time);

    track_id = file_reader->Read32();
    file_reader->Read32();   //reserved

    duration = file_reader->Read32();
    file_reader->Read64();   //reserved

    layer = file_reader->Read16();
    volume = file_reader->Read16();
    file_reader->Read16();   //reserved

    for (size_t i = 0; i < matrix.size(); i++)
        for (size_t j = 0; j < matrix[0].size(); j++)
            matrix[i][j] = file_reader->Read32();

    track_width = file_reader->Read32();
    track_height = file_reader->Read32();

    Stream *s = parser->streams[parser->stream_num-1];
    s->tkhd_width = track_width;
    s->tkhd_height = track_height;
}
