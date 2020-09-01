
cmake_minimum_required (VERSION 3.8)

project ("07_MinimumSpanningTree")

set(src
	${CMAKE_CURRENT_SOURCE_DIR}/main.c
 "MinimumSpanningTree.c" "MinimumSpanningTree.h")

add_executable(07_MinimumSpanningTree ${src})

# °üº¬¹«¹²¿â
include_directories(${CMAKE_SOURCE_DIR}/01_Introduction)
include_directories(${CMAKE_SOURCE_DIR}/07_Graph/01_MGraph)