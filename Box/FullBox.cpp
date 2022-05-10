//
// Created by kris on 2022/5/6.
//

#include "FullBox.h"

FullBox::FullBox(uint32_t size, uint32_t type, uint64_t start_pos) : Box(size, type, start_pos), version(0), flags(0) {

}

FullBox::~FullBox() {

}

void FullBox::Parse(struct Parser *parser, uint64_t start_pos) {
    FileReader *fileReader = parser->file_reader;
    fileReader->Seek(start_pos);

    version = fileReader->Read8();

    uint16_t h = fileReader->Read16();
    uint8_t  l = fileReader->Read8();
    flags = h << 16 | l;
}
