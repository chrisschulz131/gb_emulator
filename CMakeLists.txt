cmake_minimum_required(VERSION 3.10)
project(gb_emulator C)

set(CMAKE_C_STANDARD 99)

find_package(SDL2 REQUIRED)
include_directories(gb_emulator ${SDL2_INCLUDE_DIRS})

add_executable(gb_emulator main.c cpu.c cpu.h)
target_link_libraries(gb_emulator ${SDL2_LIBRARIES} )


