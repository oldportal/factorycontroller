# alfa version
# QMAKE is main buid tool for the project

cmake_minimum_required(VERSION 2.8)
project(factorycontroller)

enable_testing()

find_package(Boost REQUIRED)

include_directories(include)

set( factorycontroller_source main.cpp )

add_subdirectory( src factorycontroller )
add_subdirectory( test factorycontroller_test )
