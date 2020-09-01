
cmake_minimum_required (VERSION 3.8)

project ("03_OLGraph")

set(src
	${CMAKE_CURRENT_SOURCE_DIR}/main.c
 "OLGraph.c" "OLGraph.h")

add_executable(03_OLGraph ${src})

# °üº¬¹«¹²¿â
include_directories(${CMAKE_SOURCE_DIR}/01_Introduction)
