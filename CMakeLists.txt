cmake_minimum_required(VERSION 3.23)
project(Curves)

set(CMAKE_CXX_STANDARD 23)

add_executable(Curves src/main.cpp src/curves/Circle.cpp src/curves/Ellipse.cpp src/curves/Helix.cpp)