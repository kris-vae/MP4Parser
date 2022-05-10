//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_DATAREFBOX_H
#define MP4PARSER_DATAREFBOX_H

#include "FullBox.h"

typedef struct DataReferenceItem {
    uint32_t size;
    uint32_t type;
    std::string name;
    uint8_t version;
    std::vector<uint8_t> flags;
    std::vector<uint8_t> data;
}DataReferenceItem;

class DataRefBox : public FullBox {
public:
    uint32_t number_of_entries;
    std::vector<DataReferenceItem> data_reference_item_table;

public:
    DataRefBox(uint32_t size, uint32_t type, uint32_t start_pos);
    virtual ~DataRefBox();
    void Parse(struct Parser *parser, uint32_t start_pos) override;
};


#endif //MP4PARSER_DATAREFBOX_H
