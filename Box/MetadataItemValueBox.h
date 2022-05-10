//
// Created by kris on 2022/5/7.
//

#ifndef MP4PARSER_METADATAITEMVALUEBOX_H
#define MP4PARSER_METADATAITEMVALUEBOX_H

#include "Box.h"

class MetadataItemValueBox : public Box {
public:
    uint32_t type_indicator;
    uint32_t local_indicator;
    std::string description;
public:
    MetadataItemValueBox(uint32_t size, uint32_t type, uint32_t start_pos);
    virtual ~MetadataItemValueBox();
    void Parse(struct Parser *parser, uint32_t start_pos) override;
};


#endif //MP4PARSER_METADATAITEMVALUEBOX_H
