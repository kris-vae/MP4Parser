# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/MP4Parser_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/MP4Parser_autogen.dir/ParseCache.txt"
  "MP4Parser_autogen"
  )
endif()
