cmake_minimum_required(VERSION 3.21)
project(MP4Parser)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(MP4Parser main.cpp Box/Box.cpp Box/Box.h Parser.cpp Parser.h FileReader.cpp FileReader.h FourCC.h Box/FileTypeBox.cpp Box/FileTypeBox.h Box/FreeSpaceBox.cpp Box/FreeSpaceBox.h Box/FullBox.cpp Box/FullBox.h Box/DefaultContainerBox.cpp Box/DefaultContainerBox.h Box/MovieHeaderBox.cpp Box/MovieHeaderBox.h Box/TrackHeaderBox.cpp Box/TrackHeaderBox.h Box/ApertureDimensionsBox.cpp Box/ApertureDimensionsBox.h Box/EditListBox.cpp Box/EditListBox.h Box/MediaHeaderBox.cpp Box/MediaHeaderBox.h Box/MediaHandleRefBox.cpp Box/MediaHandleRefBox.h Box/VideoMediaHeaderBox.cpp Box/VideoMediaHeaderBox.h Box/DataRefBox.cpp Box/DataRefBox.h Box/MetadataItemKeysBox.cpp Box/MetadataItemKeysBox.h Box/SoundMediaHeaderBox.cpp Box/SoundMediaHeaderBox.h Box/SampleDescriptionBox.cpp Box/SampleDescriptionBox.h Box/DecodingTimeToSampleBox.cpp Box/DecodingTimeToSampleBox.h Box/CompositionTimeToSampleBox.cpp Box/CompositionTimeToSampleBox.h Box/CompositionToDecodeBox.cpp Box/CompositionToDecodeBox.h Box/SyncSampleBox.cpp Box/SyncSampleBox.h Box/IndependentAndDisposableSamplesBox.cpp Box/IndependentAndDisposableSamplesBox.h Box/SampleToChunkBox.cpp Box/SampleToChunkBox.h Box/SampleSizeBox.cpp Box/SampleSizeBox.h Box/ChunkOffsetBox.cpp Box/ChunkOffsetBox.h Box/MetadataItemValueBox.cpp Box/MetadataItemValueBox.h mainwindow.cpp mainwindow.h mainwindow.ui Display.cpp Display.h Define.h Box/VisualSampleEntry.cpp Box/VisualSampleEntry.h Box/AudioSampleEntry.cpp Box/AudioSampleEntry.h)
target_link_libraries(MP4Parser
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

