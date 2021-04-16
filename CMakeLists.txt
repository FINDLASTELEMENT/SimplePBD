cmake_minimum_required(VERSION 3.0)

project(softbodytest CXX)

add_executable(softbodytest constraint.cpp constraint.h consts.h edge.cpp edge.h main.cpp particle.cpp particle.h precision.h springedge.cpp springedge.h)


target_link_libraries(softbodytest sfml-graphics)
target_link_libraries(softbodytest sfml-window)
target_link_libraries(softbodytest sfml-system)


