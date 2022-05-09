//
// Created by kris on 2022/5/6.
//

#include "FileReader.h"

FileReader::FileReader() {
    fp = nullptr;
}

FileReader::~FileReader() {
    Close();
}

int FileReader::Open(const char *file_name) {
    fp = fopen(file_name, "rb");
    return fp == nullptr ? -1 : 0;
}

int FileReader::Close() {
    if (fp)
    {
        fclose(fp);
        fp = nullptr;
    }

    return 0;
}

long int FileReader::Offset() {
    return ftell(fp);
}

int FileReader::Seek(long int offset) {
    return fseek(fp, offset, SEEK_SET);
}

uint8_t FileReader::Read8() {
    uint8_t ret;
    fread(&ret, 1, 1, fp);
    return ret;
}

uint16_t FileReader::Read16() {
    uint8_t buffer[2] = {0};
    size_t size = fread(buffer, 1, 2, fp);
    return ((buffer[0] << 8) | buffer[1]);
}

uint32_t FileReader::Read32() {
//    uint16_t h = Read16();
//    uint16_t l = Read16();
//    return (h << 16) | l;
    uint8_t buffer[4] = {0};
    fread(buffer, 4, 1, fp);
    return (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];
}

uint64_t  FileReader::Read64() {
    uint64_t h = Read32();
    uint64_t l = Read32();
    return (h << 32) | l;
}

int FileReader::Skip(long int len) {
    return fseek(fp, len, SEEK_CUR);
}

int FileReader::ReadToBuffer(uint8_t *buffer, int count, int len) {
    return fread(buffer, len, count, fp);
}

int FileReader::Length() {
    int cur_pos = ftell(fp);

    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, cur_pos, SEEK_SET);

    return file_size;
}


