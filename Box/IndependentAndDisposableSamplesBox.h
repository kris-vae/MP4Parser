//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_INDEPENDENTANDDISPOSABLESAMPLESBOX_H
#define MP4PARSER_INDEPENDENTANDDISPOSABLESAMPLESBOX_H

#include "FullBox.h"

class IndependentAndDisposableSamplesBox : public FullBox {
public:
    std::vector<uint8_t> sample_dependency_flags_table;

public:
    IndependentAndDisposableSamplesBox(uint32_t size, uint32_t type, uint32_t start_pos);
    virtual ~IndependentAndDisposableSamplesBox();
    void Parse(struct Parser *parser, uint32_t start_pos) override;
};


#endif //MP4PARSER_INDEPENDENTANDDISPOSABLESAMPLESBOX_H
