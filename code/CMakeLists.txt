cmake_minimum_required(VERSION 3.2)
set(This rhatdist)
project(${This} VERSION 1.0.0)


add_subdirectory(Json)
add_subdirectory(configuration)

# add_executable(configuration main.cpp)
