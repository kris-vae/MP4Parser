//
// Created by kris on 2022/5/6.
//

#include "DefaultContainerBox.h"

DefaultContainerBox::DefaultContainerBox(uint32_t size, uint32_t type, uint64_t start_pos) : Box(size, type, start_pos) {}

DefaultContainerBox::~DefaultContainerBox() {

}

void DefaultContainerBox::Parse(struct Parser *parser, uint64_t start_pos) {
    FileReader *file_reader = parser->file_reader;
    int index = 0;

    if (type == FOURCC_trak)
        parser->AddStream();

    while(index < size - 8) {
        Box *box = nullptr;
        if (type == FOURCC_ilst)
            box = parser->ReadBox(start_pos + index, true);
        else
            box =  parser->ReadBox(start_pos + index);
        AddChild(box);
        index += box->size;
        file_reader->Seek(start_pos + index);
    }
}
