//
// Created by kris on 2022/5/6.
//

#include "CompositionToDecodeBox.h"

CompositionToDecodeBox::CompositionToDecodeBox(uint32_t size, uint32_t type, uint32_t start_pos) : FullBox(size, type,
                                                                                                          start_pos) {}

CompositionToDecodeBox::~CompositionToDecodeBox() {

}

void CompositionToDecodeBox::Parse(struct Parser *parser, uint32_t start_pos) {
    FullBox::Parse(parser, start_pos);

    shift = parser->file_reader->Read32();

    least_display_offset = parser->file_reader->Read32();
    greatest_display_offset = parser->file_reader->Read32();

    display_start_time = parser->file_reader->Read32();
    display_start_time_formatter = ConvertToFormatterTime(display_start_time);

    display_end_time = parser->file_reader->Read32();
    display_end_time_formatter = ConvertToFormatterTime(display_end_time);
}
