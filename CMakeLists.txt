cmake_minimum_required (VERSION 2.6)
project (chip8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${chip8_SOURCE_DIR}/cmake")
set(BIN_DIR ${chip8_SOURCE_DIR}/bin)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

#target_link_libraries(chip8 ${SDL2_LIBRARY})

file(GLOB SOURCES "src/*cpp")
file(GLOB HEADERS "include/*h")
add_executable(chip8 ${SOURCES} ${HEADERS})

