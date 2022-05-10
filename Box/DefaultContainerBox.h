//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_DEFAULTCONTAINERBOX_H
#define MP4PARSER_DEFAULTCONTAINERBOX_H

#include "Box.h"

class DefaultContainerBox : public Box {
public:
    DefaultContainerBox(uint32_t size, uint32_t type, uint64_t start_pos);
    virtual ~DefaultContainerBox();

    virtual void Parse(struct Parser *parser, uint64_t start_pos) override;
};


#endif //MP4PARSER_DEFAULTCONTAINERBOX_H
