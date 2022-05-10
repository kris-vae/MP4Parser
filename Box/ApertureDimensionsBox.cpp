//
// Created by kris on 2022/5/6.
//

#include "ApertureDimensionsBox.h"

ApertureDimensionsBox::ApertureDimensionsBox(uint32_t size, uint32_t type, uint64_t start_pos)
        : FullBox(size, type, start_pos) {}

ApertureDimensionsBox::~ApertureDimensionsBox() {

}

void ApertureDimensionsBox::Parse(struct Parser *parser, uint64_t start_pos) {
    FullBox::Parse(parser, start_pos);

    width = parser->file_reader->Read32();
    height = parser->file_reader->Read32();
}
