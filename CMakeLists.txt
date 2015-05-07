cmake_minimum_required (VERSION 2.6)
project (TCache)

# Set porject imformation
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

subdirs (src)

# The version number
set (TCache_MAJOR_VERSION 1)
set (TCache_MINOR_VERSION 1)

# Add personal c flags
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O0 -g -std=gnu11 ")
