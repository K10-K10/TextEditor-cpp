cmake_minimum_required(VERSION 3.16)
project(app LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
  terminal_library
  GIT_REPOSITORY https://github.com/K10-K10/Terminal-Library.git
  GIT_TAG        main   # または "v1.1.0" などのリリースタグ
)

FetchContent_MakeAvailable(terminal_library)

add_executable(app src/main.cpp)

target_link_libraries(app PRIVATE K10-K10::terminal)
