cmake_minimum_required(VERSION 3.16)
project(app LANGUAGES CXX)

add_subdirectory(lib/Terminal-Library)

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE terminal)
