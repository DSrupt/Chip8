cmake_minimum_required (VERSION 2.6)
project (chip8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${chip8_SOURCE_DIR}/cmake")
set(BIN_DIR ${chip8_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

#target_link_libraries(chip8 ${SDL2_LIBRARY})
include_directories("include")
file(GLOB SOURCES "src/*cpp")
add_executable(chip8 ${SOURCES})
target_link_libraries(chip8 ${SDL2_LIBRARY})
