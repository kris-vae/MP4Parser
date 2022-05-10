//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_MEDIAHANDLEREFBOX_H
#define MP4PARSER_MEDIAHANDLEREFBOX_H

#include "FullBox.h"

class MediaHandleRefBox : public FullBox {
public:
    uint32_t component_type;
    std::string component_type_name;

    uint32_t component_subtype;
    std::string component_subtype_name;

    uint32_t component_manufacturer;
    std::string component_manufacturer_name;

    uint32_t after_component_manufacturer_flags;
    uint32_t component_flags_mask;

    std::string component_name;

public:
    MediaHandleRefBox(uint32_t size, uint32_t type, uint64_t start_pos);
    virtual ~MediaHandleRefBox();

private:
    virtual void Parse(struct Parser *parser, uint64_t start_pos) override;
};


#endif //MP4PARSER_MEDIAHANDLEREFBOX_H
