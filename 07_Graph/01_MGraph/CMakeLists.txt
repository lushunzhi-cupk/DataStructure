
cmake_minimum_required (VERSION 3.8)

project ("01_MGraph")

set(src
	${CMAKE_CURRENT_SOURCE_DIR}/main.c
 "MGraph.c" "MGraph.h" "LinkQueue.c" "LinkQueue.h")

add_executable(01_MGraph ${src})

# °üº¬¹«¹²¿â
include_directories(${CMAKE_SOURCE_DIR}/01_Introduction)
