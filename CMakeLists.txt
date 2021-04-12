cmake_minimum_required(VERSION 3.0)

project(softbodytest)

add_executable(softbodytest main.cpp particle.h particle.cpp edge.h edge.cpp springedge.cpp springedge.h)

install(TARGETS softbodytest RUNTIME DESTINATION bin)

target_link_libraries(softbodytest libsfml-graphics.so)
target_link_libraries(softbodytest libsfml-window.so)
target_link_libraries(softbodytest libsfml-system.so)

