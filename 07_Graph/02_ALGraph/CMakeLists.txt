
cmake_minimum_required (VERSION 3.8)

project ("02_ALGraph")

set(src
	${CMAKE_CURRENT_SOURCE_DIR}/main.c
 "ALGraph.c" "ALGraph.h")

add_executable(02_ALGraph ${src})

# °üº¬¹«¹²¿â
include_directories(${CMAKE_SOURCE_DIR}/01_Introduction)
