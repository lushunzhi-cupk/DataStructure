cmake_minimum_required (VERSION 3.8)

project ("01_SqList")

set(src
	${CMAKE_CURRENT_SOURCE_DIR}/main.c
	${CMAKE_CURRENT_SOURCE_DIR}/SqList.c
	${CMAKE_CURRENT_SOURCE_DIR}/SqList.h
)

add_executable(01_SqList ${src})

# °üº¬¹«¹²¿â
include_directories(${CMAKE_SOURCE_DIR}/01_Introduction)