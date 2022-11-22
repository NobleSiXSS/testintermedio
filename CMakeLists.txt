project(NSC-test-intermedio)
cmake_minimum_required(VERSION 2.84)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin/")
set(CMAKE_CXX_STANDARD 11)

include_directories(toinclude)

add_library(${PROJECT_NAME} src/date.cpp src/book.cpp)

add_executable(main src/main.cpp)

target_link_libraries(main ${PROJECT_NAME})