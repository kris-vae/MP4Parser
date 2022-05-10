//
// Created by kris on 2022/5/6.
//

#include "IndependentAndDisposableSamplesBox.h"

IndependentAndDisposableSamplesBox::IndependentAndDisposableSamplesBox(uint32_t size, uint32_t type, uint64_t start_pos)
        : FullBox(size, type, start_pos) {}

IndependentAndDisposableSamplesBox::~IndependentAndDisposableSamplesBox() {

}

void IndependentAndDisposableSamplesBox::Parse(struct Parser *parser, uint64_t start_pos) {
    FullBox::Parse(parser, start_pos);

    uint32_t number_of_entries = size - 12;
    sample_dependency_flags_table = std::vector<uint8_t>(number_of_entries);

    for (size_t i = 0; i < sample_dependency_flags_table.size(); i++)
        sample_dependency_flags_table[i] = parser->file_reader->Read8();
}
