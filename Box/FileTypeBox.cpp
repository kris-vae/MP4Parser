//
// Created by kris on 2022/5/6.
//

#include "FileTypeBox.h"

FileTypeBox::FileTypeBox(uint32_t size, uint32_t type, uint32_t start_pos) : Box(size, type, start_pos) {
}

FileTypeBox::~FileTypeBox() {

}

void FileTypeBox::Parse(struct Parser *parser, uint32_t start_pos) {
    FileReader *file_reader = parser->file_reader;
    file_reader->Seek(start_pos);

    major_brand = file_reader->Read32();
    major_brand_name = ConvertToString(major_brand);

    minor_version = file_reader->Read32();

    size_t compatible_brands_size = (size - 16) / 4;
    compatible_brands = std::vector<uint32_t>(compatible_brands_size);
    compatible_brands_name = std::vector<std::string>(compatible_brands_size);

    for (size_t i = 0; i < compatible_brands_size; i++) {
        compatible_brands[i] = file_reader->Read32();
        compatible_brands_name[i] = ConvertToString(compatible_brands[i]);
    }
}
