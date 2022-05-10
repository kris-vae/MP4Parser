//
// Created by kris on 2022/5/6.
//

#include "EditListBox.h"

EditListBox::EditListBox(uint32_t size, uint32_t type, uint64_t start_pos) : FullBox(size, type, start_pos) {}

EditListBox::~EditListBox() {

}

void EditListBox::Parse(struct Parser *parser, uint64_t start_pos) {
    FullBox::Parse(parser, start_pos);

    FileReader *file_reader = parser->file_reader;

    number_of_entries = file_reader->Read32();
    edit_item_table = std::vector<EditItem>(number_of_entries);

    for (size_t i = 0; i < number_of_entries; i++) {
        EditItem edit_item;

        edit_item.track_duration = file_reader->Read32();
        edit_item.media_time = file_reader->Read32();
        edit_item.media_rate = file_reader->Read32();
        edit_item.media_rate_formatter = std::to_string(edit_item.media_rate >> 16) + "." + std::to_string(edit_item.media_rate & 0xffff);
        edit_item_table[i] = edit_item;
    }
}
