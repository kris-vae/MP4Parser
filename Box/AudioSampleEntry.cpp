//
// Created by kris on 2022/5/9.
//

#include "AudioSampleEntry.h"

AudioSampleEntry::AudioSampleEntry(uint32_t size, uint32_t type, uint32_t startPos) : Box(size, type, startPos) {}

AudioSampleEntry::~AudioSampleEntry() {

}

void AudioSampleEntry::Parse(struct Parser *parser, uint64_t start_pos) {
    Box::Parse(parser, start_pos);
    FileReader *file_reader = parser->file_reader;
    file_reader->Seek(start_pos);

    file_reader->Skip(6);
    file_reader->Read16(); //data_reference_index;

    file_reader->Skip(8);

    Stream *s = parser->streams[parser->stream_num - 1];
    s->channel_count = file_reader->Read16();
    s->sample_size = file_reader->Read16();

    file_reader->Read16();
    file_reader->Read16();

    s->sample_size = file_reader->Read32() >> 16;

    Box *box = parser->ReadBox(file_reader->Offset());
    AddChild(box);
}
