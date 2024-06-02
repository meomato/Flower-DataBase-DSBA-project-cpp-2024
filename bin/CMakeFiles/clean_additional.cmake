# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "BloomBaze_autogen"
  "CMakeFiles\\BloomBaze_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\BloomBaze_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\runTests_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\runTests_autogen.dir\\ParseCache.txt"
  "external\\googletest\\googlemock\\CMakeFiles\\gmock_autogen.dir\\AutogenUsed.txt"
  "external\\googletest\\googlemock\\CMakeFiles\\gmock_autogen.dir\\ParseCache.txt"
  "external\\googletest\\googlemock\\CMakeFiles\\gmock_main_autogen.dir\\AutogenUsed.txt"
  "external\\googletest\\googlemock\\CMakeFiles\\gmock_main_autogen.dir\\ParseCache.txt"
  "external\\googletest\\googlemock\\gmock_autogen"
  "external\\googletest\\googlemock\\gmock_main_autogen"
  "external\\googletest\\googletest\\CMakeFiles\\gtest_autogen.dir\\AutogenUsed.txt"
  "external\\googletest\\googletest\\CMakeFiles\\gtest_autogen.dir\\ParseCache.txt"
  "external\\googletest\\googletest\\CMakeFiles\\gtest_main_autogen.dir\\AutogenUsed.txt"
  "external\\googletest\\googletest\\CMakeFiles\\gtest_main_autogen.dir\\ParseCache.txt"
  "external\\googletest\\googletest\\gtest_autogen"
  "external\\googletest\\googletest\\gtest_main_autogen"
  "runTests_autogen"
  )
endif()
