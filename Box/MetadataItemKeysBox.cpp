//
// Created by kris on 2022/5/6.
//

#include "MetadataItemKeysBox.h"

MetadataItemKeysBox::MetadataItemKeysBox(uint32_t size, uint32_t type, uint64_t start_pos) : FullBox(size, type,
                                                                                                    start_pos) {}

MetadataItemKeysBox::~MetadataItemKeysBox() {

}

void MetadataItemKeysBox::Parse(struct Parser *parser, uint64_t start_pos) {
    FullBox::Parse(parser, start_pos);

    FileReader *file_reader = parser->file_reader;

    number_of_entries = file_reader->Read32();
    key_item_table = std::vector<KeyItem>(number_of_entries);

    for (size_t i = 0; i < key_item_table.size(); i++) {
        KeyItem item;

        item.entry_size = file_reader->Read32();
        item.name_space = file_reader->Read32();
        item.name_space_str = ConvertToString(item.name_space);

        item.value = std::string(item.entry_size - 8, '0');
        for (size_t j = 0; j < item.value.size(); j++)
            item.value[j] = file_reader->Read8();

        key_item_table[i] = item;
    }
}
