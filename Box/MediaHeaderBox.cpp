//
// Created by kris on 2022/5/6.
//

#include "MediaHeaderBox.h"

MediaHeaderBox::MediaHeaderBox(uint32_t size, uint32_t type, uint64_t start_pos) : FullBox(size, type, start_pos) {}

MediaHeaderBox::~MediaHeaderBox() {

}

static void make_language_iso639(uint16_t lang, std::string &language)
{
    language[3] = 0;
    language[2] = (lang & 0x001f) + 0x60;
    lang >>= 5;
    language[1] = (lang & 0x001f) + 0x60;
    lang >>= 5;
    language[0] = (lang & 0x001f) + 0x60;
}

void MediaHeaderBox::Parse(struct Parser *parser, uint64_t start_pos) {
    FullBox::Parse(parser, start_pos);

    FileReader *file_reader = parser->file_reader;

    creation_time = file_reader->Read32();
    creation_time_formatter = ConvertToFormatterTime(creation_time);

    modification_time = file_reader->Read32();
    modification_time_formatter = ConvertToFormatterTime(modification_time);

    time_scale = file_reader->Read32();
    duration = file_reader->Read32();
    language = file_reader->Read16();
    //ISO Language Code
//    char c = (((language >> 11) & 0x1f) + 96) ;
//    char d = (((language >> 6) & 0x1f) + 96);
//    char e = (((language >> 1) & 0x1f) + 96);

    quality = file_reader->Read16();

    parser->duration = duration;
    parser->time_scale = time_scale;

    Stream *s = parser->streams[parser->stream_num-1];
    s->language = std::string(4, '0');
    make_language_iso639(language, s->language);
}
