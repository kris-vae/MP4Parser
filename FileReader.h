//
// Created by kris on 2022/5/6.
//

#ifndef MP4PARSER_FILEREADER_H
#define MP4PARSER_FILEREADER_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

class FileReader {
public:
    FileReader();
    ~FileReader();

public:
    int Open(const char *file_name);
    int Close();

    long int Offset();
    int Seek(long int offset);
    int Skip(long int len);
    int Length();

    uint8_t Read8();
    uint16_t Read16();
    uint32_t Read32();
    uint64_t Read64();
    int ReadToBuffer(uint8_t *buffer, int count, int len = 1);

private:
    FILE *fp;
};

#endif //MP4PARSER_FILEREADER_H
