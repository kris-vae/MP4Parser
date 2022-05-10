//
// Created by kris on 2022/5/6.
//

#include "Parser.h"
#include "Box/DefaultContainerBox.h"
#include "Box/FileTypeBox.h"
#include "Box/FreeSpaceBox.h"
#include "Box/MovieHeaderBox.h"
#include "Box/TrackHeaderBox.h"
#include "Box/ApertureDimensionsBox.h"
#include "Box/EditListBox.h"
#include "Box/MediaHeaderBox.h"
#include "Box/MediaHandleRefBox.h"
#include "Box/VideoMediaHeaderBox.h"
#include "Box/DataRefBox.h"
#include "Box/MetadataItemKeysBox.h"
#include "Box/SoundMediaHeaderBox.h"
#include "Box/SampleDescriptionBox.h"
#include "Box/DecodingTimeToSampleBox.h"
#include "Box/CompositionTimeToSampleBox.h"
#include "Box/CompositionToDecodeBox.h"
#include "Box/SyncSampleBox.h"
#include "Box/IndependentAndDisposableSamplesBox.h"
#include "Box/SampleToChunkBox.h"
#include "Box/SampleSizeBox.h"
#include "Box/ChunkOffsetBox.h"
#include "Box/MetadataItemValueBox.h"

Parser::~Parser() {
    if (file_reader != nullptr) {
        delete file_reader;
        file_reader = nullptr;
    }

    if (root != nullptr) DestroyBox(root);

    for (int i = 0; i < stream_num; i++) {
        delete streams[i];
    }
}

Parser::Parser() {
    file_reader = nullptr;
    init();
}

Parser::Parser(FileReader *fileReader) : file_reader(fileReader) {
    init();
}

void Parser::init() {
    root = new Box(0, 0, 0);
    stream_num = 0;
    memset(streams, 0, sizeof(Stream*)*MAX_STREAM_COUNT);

    duration = 0;
    time_scale = 1;
    width = 0;
    height = 0;
}

Box *Parser::CreateBox(uint32_t size, uint32_t type, uint64_t start_pos, bool is_item_box) {
    Box *box = nullptr;

    if (is_item_box) {
        box = new MetadataItemValueBox(size, type, start_pos);
        return box;
    }

    switch (type) {
        case FOURCC_moov:
        case FOURCC_trak:
        case FOURCC_tapt:
        case FOURCC_edts:
        case FOURCC_mdia:
        case FOURCC_minf:
        case FOURCC_dinf:
        case FOURCC_stbl:
        case FOURCC_ilst:
        case FOURCC_udta:
            box = new DefaultContainerBox(size, type, start_pos);
            break;
        case FOURCC_clef:
        case FOURCC_prof:
        case FOURCC_enof:
            box = new ApertureDimensionsBox(size, type, start_pos);
            break;
        case FOURCC_ftyp:
            box = new FileTypeBox(size, type, start_pos);
            break;
        case FOURCC_free:
            box = new FreeSpaceBox(size, type, start_pos);
            break;
        case FOURCC_mvhd:
            box = new MovieHeaderBox(size, type, start_pos);
            break;
        case FOURCC_tkhd:
            box = new TrackHeaderBox(size, type, start_pos);
            break;
        case FOURCC_elst:
            box = new EditListBox(size, type, start_pos);
            break;
        case FOURCC_mdhd:
            box = new MediaHeaderBox(size, type, start_pos);
            break;
        case FOURCC_hdlr:
            box = new MediaHandleRefBox(size, type, start_pos);
            break;
        case FOURCC_vmhd:
            box = new VideoMediaHeaderBox(size, type, start_pos);
            break;
        case FOURCC_dref:
            box = new DataRefBox(size, type, start_pos);
            break;
        case FOURCC_keys:
            box = new MetadataItemKeysBox(size, type, start_pos);
            break;
        case FOURCC_smhd:
            box = new SoundMediaHeaderBox(size, type, start_pos);
            break;
        case FOURCC_stsd:
            box = new SampleDescriptionBox(size, type, start_pos);
            break;
        case FOURCC_stts:
            box = new DecodingTimeToSampleBox(size, type, start_pos);
            break;
        case FOURCC_ctts:
            box = new CompositionTimeToSampleBox(size, type, start_pos);
            break;
        case FOURCC_cslg:
            box = new CompositionToDecodeBox(size, type, start_pos);
            break;
        case FOURCC_stss:
            box = new SyncSampleBox(size, type, start_pos);
            break;
        case FOURCC_sdtp:
            box = new IndependentAndDisposableSamplesBox(size, type, start_pos);
            break;
        case FOURCC_stsc:
            box = new SampleToChunkBox(size, type, start_pos);
            break;
        case FOURCC_stsz:
            box = new SampleSizeBox(size, type, start_pos);
            break;
        case FOURCC_stco:
            box = new ChunkOffsetBox(size, type, start_pos);
            break;
        case FOURCC_data:
            box = new MetadataItemValueBox(size, type, start_pos);
            break;
        case FOURCC_meta:
            if (isMOVFile())
                box = new DefaultContainerBox(size, type, start_pos);
            else
                box = new Box(size, type, start_pos);
            break;
        default:
            return new Box(size, type, start_pos);
    }

    return box;
}

Box *Parser::ReadBox(uint64_t start_pos, bool is_item_box) {
    uint32_t offset = 0;

    uint32_t size = file_reader->Read32();
    uint32_t type = file_reader->Read32();offset += 8;

    if (size == 1) {
        size = file_reader->Read64();
        offset += 8;
    }

    Box *box = CreateBox(size, type, start_pos, is_item_box);
    std::cout << "type = " << box->name << ", start position = " << box->start_pos << ", size = " << box->size << ", next start position = " << box->start_pos + box->size << std::endl;
    box->Parse(this, start_pos + offset);

    return box;
}

int Parser::Parse(const char *path) {
    file_path = std::string(path);
    if (file_reader == nullptr) file_reader = new FileReader();

    int ret = file_reader->Open(path);
    if (ret != 0) {
        std::cout << "Open file failed with info:" << strerror(errno) << std::endl;
        return -1;
    }

    uint32_t file_size = file_reader->Length();
    if (file_size < 8) {
        std::cout << "File size is lower than 8" << std::endl;
        return -1;
    }

    file_reader->Read32();
    uint32_t type = file_reader->Read32();
    if (type != FOURCC_ftyp) return -1;

    file_reader->Seek(0);
    uint32_t current_pos = 0;

    while (current_pos < file_size) {
        Box *box = ReadBox( current_pos);
        root->AddChild(box);
        current_pos += box->size;
        file_reader->Seek(current_pos);
    }

    for (uint32_t i = 0; i < stream_num; i++)
        SamplePosition(streams[i]);

    return 0;
}

bool Parser::isMOVFile() {
    size_t pos = file_path.find_last_of('.');
    return file_path.substr(pos + 1) == "mov" ? true : false;
}

Box *Parser::ParseResult() {
    return root;
}

Stream *Parser::AddStream() {
    Stream *s = new Stream;
    memset(s, 0, sizeof(Stream));
    s->index = stream_num;
    streams[stream_num] = s;
    stream_num++;
    return s;
}

Stream *Parser::VideoStream() {
    Stream *s = nullptr;
    for (int i = 0; i < stream_num; i++) {
        s = streams[i];
        if (s->type == HANDLER_VIDEO)
            return s;
    }
    return s;
}

Stream *Parser::AudioStream() {
    Stream *s = nullptr;
    for (int i = 0; i < stream_num; i++) {
        s = streams[i];
        if (s->type == HANDLER_AUDIO)
            return s;
    }
    return s;
}

void Parser::SamplePosition(struct Stream *s) {
    uint32_t sample_count = s->stsz_count;
    uint32_t chunk_count = s->stco_count;

    if (sample_count > 0) s->sample_position = new uint64_t[sample_count];

    uint32_t remain_chunk_count = chunk_count;
    uint32_t sample_index = 0;

    for (uint32_t i = 0; i < s->stsc_count; i++) {
        uint32_t c_count = 0;

        if (i != s->stsc_count - 1) {
            c_count = s->stsc_data[i+1].first_chunk - s->stsc_data[i].first_chunk;
            remain_chunk_count -= c_count;
        }
        else {
            c_count = remain_chunk_count;
        }

        for (uint32_t j = 0; j < c_count; j++) {
            uint32_t chunk_index = s->stsc_data[i].first_chunk + j;
            uint64_t offset = s->stco_data[chunk_index - 1];

            for (uint32_t k = 0; k < s->stsc_data[i].samples_per_chunk; k++) {
                s->sample_position[sample_index] = offset;
                offset += s->stsz_data[sample_index];
                sample_index++;
                if (sample_index > sample_count) return;
            }
        }
    }
}

void Parser::DestroyBox(Box *box) {
    if (box->child_head) DestroyBox(box->child_head);
    if (box->next) DestroyBox(box->next);
    delete box;
}



