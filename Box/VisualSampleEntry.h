//
// Created by kris on 2022/5/9.
//

#ifndef MP4PARSER_VISUALSAMPLEENTRY_H
#define MP4PARSER_VISUALSAMPLEENTRY_H

#include "Box.h"

class VisualSampleEntry : public Box{
public:
    VisualSampleEntry(uint32_t size, uint32_t type, uint32_t startPos);
    virtual ~VisualSampleEntry();
    void Parse(struct Parser *parser, uint64_t start_pos) override;
};


#endif //MP4PARSER_VISUALSAMPLEENTRY_H
