cmake_minimum_required(VERSION 3.0)

project(softbodytest CXX)

add_executable(softbodytest constraint.cpp constraint.h consts.h edge.cpp edge.h main.cpp particle.cpp particle.h precision.h springedge.cpp springedge.h)

if(CMAKE_EXE_LINKER_FLAGS STREQUAL "-static")
	target_compile_definitions(softbodytest PUBLIC SFML_STATIC)
	target_link_libraries(softbodytest sfml-graphics-s)
	target_link_libraries(softbodytest sfml-window-s)
	target_link_libraries(softbodytest sfml-system-s)
	target_link_libraries(softbodytest opengl32)
	target_link_libraries(softbodytest winmm)
	target_link_libraries(softbodytest gdi32)
else()
	target_link_libraries(softbodytest "sfml-graphics")
	target_link_libraries(softbodytest "sfml-window")
	target_link_libraries(softbodytest "sfml-system")
endif()
