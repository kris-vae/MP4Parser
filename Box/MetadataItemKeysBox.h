//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_METADATAITEMKEYSBOX_H
#define MP4PARSER_METADATAITEMKEYSBOX_H

#include "FullBox.h"

typedef struct KeyItem {
    uint32_t entry_size;
    uint32_t name_space;
    std::string name_space_str;
    std::string value;
}KeyItem;

class MetadataItemKeysBox : public FullBox {
public:
    uint32_t number_of_entries;
    std::vector<KeyItem> key_item_table;

public:
    MetadataItemKeysBox(uint32_t size, uint32_t type, uint64_t start_pos);

    virtual ~MetadataItemKeysBox();

    void Parse(struct Parser *parser, uint64_t start_pos) override;
};


#endif //MP4PARSER_METADATAITEMKEYSBOX_H
