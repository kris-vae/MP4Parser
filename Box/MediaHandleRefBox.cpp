//
// Created by kris on 2022/5/6.
//

#include "MediaHandleRefBox.h"

MediaHandleRefBox::MediaHandleRefBox(uint32_t size, uint32_t type, uint64_t start_pos) : FullBox(size, type, start_pos) {}

MediaHandleRefBox::~MediaHandleRefBox() {

}

void MediaHandleRefBox::Parse(struct Parser *parser, uint64_t start_pos) {
    FullBox::Parse(parser, start_pos);

    Stream *s = nullptr;
    if (parser->stream_num > 0)
        s = parser->streams[parser->stream_num - 1];
    FileReader *file_reader = parser->file_reader;

    component_type = file_reader->Read32();
    component_type_name = ConvertToString(component_type);

    component_subtype = file_reader->Read32();
    component_subtype_name = ConvertToString(component_subtype);
    if (s && s->type == 0) s->type = component_subtype;
    component_manufacturer = file_reader->Read32();
    component_manufacturer_name = ConvertToString(component_manufacturer);

    after_component_manufacturer_flags = file_reader->Read32();

    component_flags_mask = file_reader->Read32();

    for (int i = 0; i < size - 32; i++) {
        uint8_t c = file_reader->Read8();
        if (c >= ' ')
            component_name.push_back(c);
    }

    if (s != nullptr && s->handle.empty()) s->handle = component_name;
}
