cmake_minimum_required(VERSION 3.14)

set(CMAKE_TOOLCHAIN_FILE
    ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
    CACHE STRING "Vcpkg toolchain file")

project(test-apache-orc CXX)

find_package(protobuf CONFIG REQUIRED)
find_package(ZLIB REQUIRED)
find_package(Snappy CONFIG REQUIRED)

find_library(LZ4_LIBRARY NAMES lz4d lz4)
find_library(ZSTD_LIBRARY NAMES zstd)
find_library(ORC_LIBRARY NAMES orc)

add_executable(orc-test main.cpp)
target_compile_features(orc-test PRIVATE cxx_std_11)
target_link_libraries(orc-test PRIVATE ${ORC_LIBRARY} protobuf::libprotoc protobuf::libprotobuf Snappy::snappy ${LZ4_LIBRARY} ${ZSTD_LIBRARY} ZLIB::ZLIB)
