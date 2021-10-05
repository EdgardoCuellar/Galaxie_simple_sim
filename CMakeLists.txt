cmake_minimum_required(VERSION 3.17)
project(Galaxie)

set(CMAKE_CXX_STANDARD 20)
find_package(SDL2 REQUIRED)
include_directories( ${SDL2_INCLUDE_DIR} )

add_executable(Galaxie main.cpp Screen.cpp Point.cpp Stars.cpp)

target_link_libraries(Galaxie ${SDL2_LIBRARY} )
