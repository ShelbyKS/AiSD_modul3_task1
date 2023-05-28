cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)

project(main)

file(GLOB SOURCES
    src/*.cpp
    include/*.hpp
)

add_library(graph_lib STATIC ${SOURCES})
target_include_directories(graph_lib PUBLIC include)

add_executable(main main.cpp)
target_link_libraries(main graph_lib)
