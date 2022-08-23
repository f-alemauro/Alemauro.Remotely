cmake_minimum_required(VERSION 3.0.0)
project(Alemauro.Remotely VERSION 0.1.0)

enable_testing()

add_executable(Alemauro.Remotely src/main.cpp)
add_library(Remotely src/remotely.cpp)
target_link_libraries(Alemauro.Remotely Remotely)