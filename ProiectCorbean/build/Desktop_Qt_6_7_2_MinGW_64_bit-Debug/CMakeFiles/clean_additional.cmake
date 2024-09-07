# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ProiectCorbean_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ProiectCorbean_autogen.dir\\ParseCache.txt"
  "ProiectCorbean_autogen"
  )
endif()
