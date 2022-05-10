//
// Created by kris on 2022/5/6.
//

#include <iomanip>
#include "Box.h"

const uint32_t interval_second = 2082816000;

Box::Box(uint32_t size, uint32_t type, uint64_t start_pos) : size(size), type(type), start_pos(start_pos) {
    name = ConvertToString(type);
    child_head = nullptr;
    child_trail = nullptr;
    next = nullptr;
}

Box::~Box() {
    child_trail = nullptr;
    child_head = nullptr;
    next = nullptr;
    size = 0;
    type = 0;
}

std::string Box::Description() {
    return std::string ("offset = " + std::to_string(start_pos) + ", " + "len = " + std::to_string(size));
}

std::string Box::ConvertToString(uint32_t bits) {
    std::string str(4, '0');

    str[0] = bits >> 24;
    str[1] = bits >> 16 & 0xff;
    str[2] = bits >> 8 & 0xff;
    str[3] = bits & 0xff;

    return str;
}

void Box::AddChild(Box *child) {
    if (child == nullptr)
        return ;
    if (child_head == nullptr && child_trail == nullptr) {
        child_head = child_trail = child;
    }
    else {
        child_trail->next = child;
        child_trail = child;
    }

}

std::string Box::ConvertToFormatterTime(uint32_t time) {
    std::time_t time_stamp = time - interval_second;
    std::tm *t = std::gmtime(&time_stamp);

    std::stringstream ss;
    ss << std::put_time(t, "%Y-%m-%d %H:%M:%S %p");
    return ss.str();
}

void Box::Parse(struct Parser *parser, uint64_t start_pos) {

}
