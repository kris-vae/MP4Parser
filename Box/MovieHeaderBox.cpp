//
// Created by kris on 2022/5/6.
//

#include "MovieHeaderBox.h"

MovieHeaderBox::MovieHeaderBox(uint32_t size, uint32_t type, uint64_t start_pos) : FullBox(size, type, start_pos) {
    reserved = std::vector<uint8_t>(10);
    matrix = std::vector<std::vector<uint32_t>>(3,std::vector<uint32_t>(3));
}

MovieHeaderBox::~MovieHeaderBox() {

}

void MovieHeaderBox::Parse(struct Parser *parser, uint64_t start_pos) {
    FullBox::Parse(parser, start_pos);

    FileReader *file_reader = parser->file_reader;

    creation_time = file_reader->Read32();
    creation_time_formatter = ConvertToFormatterTime(creation_time);

    modification_time = file_reader->Read32();
    modification_time_formatter = ConvertToFormatterTime(modification_time);

    time_scale = file_reader->Read32();
    duration = file_reader->Read32();

    preferred_rate = file_reader->Read32();
    preferred_rate_formatter = std::to_string(preferred_rate >> 16) + "." + std::to_string(preferred_rate & 0xffff);

    preferred_volume = file_reader->Read16();
    preferred_volume_formatter = std::to_string(preferred_volume >> 8) + "." + std::to_string(preferred_volume & 0xff);

    for (size_t i = 0; i < reserved.size(); i++) reserved[i] = file_reader->Read8();

    for (size_t i = 0; i < matrix.size(); i++)
        for (size_t j = 0; j < matrix[0].size(); j++)
            matrix[i][j] = file_reader->Read32();

    preview_time = file_reader->Read32();
    preview_time_formatter = ConvertToFormatterTime(preview_time);

    poster_time = file_reader->Read32();
    poster_time_formatter = ConvertToFormatterTime(poster_time);

    selection_time = file_reader->Read32();
    selection_time_formatter = ConvertToFormatterTime(selection_time);

    selection_duration = file_reader->Read32();

    current_time = file_reader->Read32();
    current_time_formatter = ConvertToFormatterTime(current_time);

    next_track_id = file_reader->Read32();
}
