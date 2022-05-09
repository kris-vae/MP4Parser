//
// Created by kris on 2022/5/9.
//

#ifndef MP4PARSER_DEFINE_H
#define MP4PARSER_DEFINE_H

#include <string>
#include <vector>
#include "stdint.h"

const uint16_t MAX_STREAM_COUNT = 10;

typedef struct CompositionOffsetItem{
    uint32_t sample_count;
    uint32_t sample_offset;
}CompositionOffsetItem;

typedef struct SampleToChunkItem {
    uint32_t first_chunk;
    uint32_t samples_per_chunk;
    uint32_t sample_description_id;
}SampleToChunkItem;

typedef struct TimeToSampleItem {
    uint32_t sample_count;
    uint32_t sample_duration;
}TimeToSampleItem;

typedef struct Stream {
    uint32_t index;
    uint32_t type;
    uint32_t tkhd_width;
    uint32_t tkhd_height;
    uint16_t width;
    uint16_t height;
    uint32_t channel_count;
    uint32_t sample_size;
    uint32_t sample_rate;
    std::string language;
    uint8_t codec_name[32];

    uint32_t stts_count;
    std::vector<TimeToSampleItem> stts_data;

    uint32_t stss_count;
    std::vector<uint32_t> stss_data;

    uint32_t ctts_count;
    std::vector<CompositionOffsetItem> ctts_data;

    uint32_t stco_count;
    std::vector<uint32_t> stco_data;

    uint32_t stsc_count;
    std::vector<SampleToChunkItem> stsc_data;

    uint32_t default_sample_size;
    uint32_t stsz_count;
    std::vector<uint32_t> stsz_data;

    uint64_t *sample_position;

}Stream;

#endif //MP4PARSER_DEFINE_H
