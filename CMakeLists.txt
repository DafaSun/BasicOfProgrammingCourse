cmake_minimum_required(VERSION 3.20)
project(course C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(libs)
add_executable(course main.c libs/data_structures/string_/string_.c libs/data_structures/string_/string_.h)

target_link_libraries(course data_structures)
target_link_libraries(course algorithms)
#target_link_libraries(course string_)
