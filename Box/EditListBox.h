//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_EDITLISTBOX_H
#define MP4PARSER_EDITLISTBOX_H

#include "FullBox.h"

typedef struct EditItem {
    uint32_t track_duration;
    uint32_t media_time;
    uint32_t media_rate;
    std::string media_rate_formatter;
}EditItem;

class EditListBox : public FullBox {
public:
    uint32_t number_of_entries;
    std::vector<EditItem> edit_item_table;

public:
    EditListBox(uint32_t size, uint32_t type, uint32_t start_pos);
    virtual ~EditListBox();
    void Parse(struct Parser *parser, uint32_t start_pos) override;
};


#endif //MP4PARSER_EDITLISTBOX_H
