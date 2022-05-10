//
// Created by kris on 2022/5/7.
//

#include "MetadataItemValueBox.h"

MetadataItemValueBox::MetadataItemValueBox(uint32_t size, uint32_t type, uint64_t start_pos) : Box(size, type, start_pos) {}

MetadataItemValueBox::~MetadataItemValueBox() {

}

void MetadataItemValueBox::Parse(struct Parser *parser, uint64_t start_pos) {
    type_indicator = parser->file_reader->Read32();
    local_indicator = parser->file_reader->Read32();

    for (int i = 0; i < size - 16; i++) {
        char c = parser->file_reader->Read8();
        if (c >= ' ')
            description.push_back(c);
    }
}
