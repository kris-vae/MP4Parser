//
// Created by kris on 2022/5/6.
//

#include "VideoMediaHeaderBox.h"

VideoMediaHeaderBox::VideoMediaHeaderBox(uint32_t size, uint32_t type, uint64_t start_pos) : FullBox(size, type, start_pos) {}

VideoMediaHeaderBox::~VideoMediaHeaderBox() {

}

void VideoMediaHeaderBox::Parse(struct Parser *parser, uint64_t start_pos) {
    FullBox::Parse(parser, start_pos);

    graphics_mode = parser->file_reader->Read16();
    red = parser->file_reader->Read16();
    green = parser->file_reader->Read16();
    blue = parser->file_reader->Read16();
}
