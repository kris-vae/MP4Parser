//
// Created by kris on 2022/5/6.
//

#include "DataRefBox.h"

DataRefBox::DataRefBox(uint32_t size, uint32_t type, uint64_t start_pos) : FullBox(size, type, start_pos) {}

DataRefBox::~DataRefBox() {

}

void DataRefBox::Parse(struct Parser *parser, uint64_t start_pos) {
    FullBox::Parse(parser, start_pos);

    FileReader *file_reader = parser->file_reader;
    number_of_entries = file_reader->Read32();
    data_reference_item_table = std::vector<DataReferenceItem>(number_of_entries);

    for (size_t i = 0; i < data_reference_item_table.size(); i++) {
        DataReferenceItem item;
        int count_size = 12;    //header 12 bytes, include 'size'(4bytes), 'type'(4bytes), 'version'(1bytes) and 'flags'(3bytes) fields;

        item.size = file_reader->Read32();
        item.type = file_reader->Read32();
        item.name = ConvertToString(item.type);
        item.version = file_reader->Read8();

        item.flags = std::vector<uint8_t>(3);
        for (size_t j = 0; j < item.flags.size(); j++)
            item.flags[j] = file_reader->Read8();

        int data_size = item.size - count_size;
        item.data = std::vector<uint8_t>(data_size);

        for (size_t j = 0; j < item.data.size(); j++)
            item.data[j] = file_reader->Read8();

        data_reference_item_table[i] = item;
    }
}
