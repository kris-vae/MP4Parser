//
// Created by kris on 2022/5/6.
//

#include "FreeSpaceBox.h"

FreeSpaceBox::FreeSpaceBox(uint32_t size, uint32_t type, uint64_t start_pos) : Box(size, type, start_pos) {
    data = std::vector<uint8_t>(size - 8);
}

FreeSpaceBox::~FreeSpaceBox() {

}

void FreeSpaceBox::Parse(struct Parser *parser, uint64_t start_pos) {
    for (size_t i = 0; i < size - 8; i++) data[i] = parser->file_reader->Read8();
}
