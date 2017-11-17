cmake_minimum_required(VERSION 3.8)
project(sorting)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCE_FILES src/main.cpp src/RandomListGenerator.cpp include/RandomListGenerator.h src/MultiSorter.cpp include/MultiSorter.h)
add_executable(sorting ${SOURCE_FILES})