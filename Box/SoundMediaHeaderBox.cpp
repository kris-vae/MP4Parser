//
// Created by kris on 2022/5/6.
//

#include "SoundMediaHeaderBox.h"

SoundMediaHeaderBox::SoundMediaHeaderBox(uint32_t size, uint32_t type, uint32_t start_pos) : FullBox(size, type,
                                                                                                    start_pos) {}

SoundMediaHeaderBox::~SoundMediaHeaderBox() {

}

void SoundMediaHeaderBox::Parse(struct Parser *parser, uint32_t start_pos) {
    FullBox::Parse(parser, start_pos);

    balance = parser->file_reader->Read16();
    parser->file_reader->Read16();  //reserved
}
