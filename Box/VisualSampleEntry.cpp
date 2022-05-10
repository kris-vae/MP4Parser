//
// Created by kris on 2022/5/9.
//

#include "VisualSampleEntry.h"

VisualSampleEntry::VisualSampleEntry(uint32_t size, uint32_t type, uint32_t startPos) : Box(size, type, startPos) {}

VisualSampleEntry::~VisualSampleEntry() {

}

void VisualSampleEntry::Parse(struct Parser *parser, uint64_t start_pos) {
    Box::Parse(parser, start_pos);
    FileReader *file_reader = parser->file_reader;
    file_reader->Seek(start_pos);

    file_reader->Skip(6);
    file_reader->Read16(); //data_reference_index;

    file_reader->Skip(16);

    Stream *s = parser->streams[parser->stream_num - 1];
    s->width = file_reader->Read16();
    s->height = file_reader->Read16();

    file_reader->Read32(); //horizresolution
    file_reader->Read32(); //vertresolution
    file_reader->Read32(); //reserved
    file_reader->Read16(); //frame_count

    int len = file_reader->Read8();
    if (len > 31) len = 31;

    file_reader->ReadToBuffer(s->codec_name, len);
    file_reader->Skip(31 - len);

    file_reader->Read16();
    file_reader->Read16();

    Box *box = parser->ReadBox(file_reader->Offset());
    AddChild(box);
}
