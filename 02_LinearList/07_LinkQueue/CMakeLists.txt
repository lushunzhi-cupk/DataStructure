
cmake_minimum_required (VERSION 3.8)

project ("07_LinkQueue")

set(src
	${CMAKE_CURRENT_SOURCE_DIR}/main.c
	${CMAKE_CURRENT_SOURCE_DIR}/LinkQueue.c
)

add_executable(07_LinkQueue ${src})

# °üº¬¹«¹²¿â
include_directories(${CMAKE_SOURCE_DIR}/01_Introduction)