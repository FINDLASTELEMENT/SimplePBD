cmake_minimum_required(VERSION 3.0)

project(softbodytest)

add_executable(softbodytest main.cpp)

install(TARGETS softbodytest RUNTIME DESTINATION bin)
