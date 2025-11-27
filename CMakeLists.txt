project(lab_8 LANGUAGES CXX)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(car_lib src/car.h src/car.cpp)
target_link_libraries(car_lib PRIVATE Qt6::Core)

add_library(plane_lib src/plane.h src/plane.cpp)
target_link_libraries(plane_lib PRIVATE Qt6::Core)

add_subdirectory(tests)
