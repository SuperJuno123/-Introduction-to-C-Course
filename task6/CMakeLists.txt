cmake_minimum_required(VERSION 3.0)
# project name and primary language
project(lab6 CXX)
# version of required C++ standard and compilation flags
set(CMAKE_CXX_STANDARD 14)
# source files folder
add_executable(lab6 main.cpp)

include_directories(LinkedList)
add_subdirectory(LinkedList)

target_link_libraries(lab6 LinkedList)

enable_testing()
add_subdirectory(tests)
