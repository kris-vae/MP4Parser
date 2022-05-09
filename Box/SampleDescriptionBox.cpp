//
// Created by kris on 2022/5/6.
//

#include "SampleDescriptionBox.h"
#include "VisualSampleEntry.h"
#include "AudioSampleEntry.h"

SampleDescriptionBox::SampleDescriptionBox(uint32_t size, uint32_t type, uint32_t start_pos) : FullBox(size, type,
                                                                                                      start_pos) {}

SampleDescriptionBox::~SampleDescriptionBox() {

}

void SampleDescriptionBox::Parse(struct Parser *parser, uint32_t start_pos) {
    FullBox::Parse(parser, start_pos);
    Stream *s = parser->streams[parser->stream_num - 1];
    FileReader *file_reader = parser->file_reader;
    number_of_entries = file_reader->Read32();
    sample_description_item_table = std::vector<SampleDescriptionItem>(number_of_entries);

    int index = 8;
    for (size_t i = 0; i < sample_description_item_table.size(); i++) {

        Box *box = nullptr;
        uint32_t size = file_reader->Read32();
        uint32_t type = file_reader->Read32();

        if (s->type == HANDLER_VIDEO)
            box = new VisualSampleEntry(size, type, index + start_pos);
        else if(s->type == HANDLER_AUDIO)
            box = new AudioSampleEntry(size, type, index + start_pos);
        else
            box = new Box(size, type, index + start_pos);

        box->Parse(parser, start_pos + index);
        AddChild(box);
        index += box->size;
        file_reader->Seek(start_pos + index);
    }
}
