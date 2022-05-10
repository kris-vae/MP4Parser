//
// Created by kris on 2022/5/9.
//

#ifndef MP4PARSER_AUDIOSAMPLEENTRY_H
#define MP4PARSER_AUDIOSAMPLEENTRY_H

#include "Box.h"

class AudioSampleEntry : public Box {
public:
    AudioSampleEntry(uint32_t size, uint32_t type, uint32_t startPos);
    virtual ~AudioSampleEntry();
    void Parse(struct Parser *parser, uint64_t start_pos) override;
};


#endif //MP4PARSER_AUDIOSAMPLEENTRY_H
