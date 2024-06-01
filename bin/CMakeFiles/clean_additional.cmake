# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "BloomBaze_autogen"
  "CMakeFiles\\BloomBaze_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\BloomBaze_autogen.dir\\ParseCache.txt"
  )
endif()
