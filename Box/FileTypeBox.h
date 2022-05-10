//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_FILETYPEBOX_H
#define MP4PARSER_FILETYPEBOX_H

#include "Box.h"

class FileTypeBox : public Box{
public:
    uint32_t major_brand;
    std::string major_brand_name;
    uint32_t minor_version;
    std::vector<uint32_t> compatible_brands;
    std::vector<std::string> compatible_brands_name;

public:
    FileTypeBox(uint32_t size, uint32_t type, uint64_t start_pos);
    virtual ~FileTypeBox();

    virtual void Parse(struct Parser *parser, uint64_t start_pos) override;
};


#endif //MP4PARSER_FILETYPEBOX_H
