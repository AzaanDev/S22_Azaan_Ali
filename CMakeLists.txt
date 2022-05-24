cmake_minimum_required(VERSION 3.16)

project(Lucid)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}})

if(WIN32)
	add_definitions(-DMANIAC_WINDOWS)
elseif(APPLE)
	add_definitions(-DMANIAC_MACOS)
elseif(UNIX)
	add_definitions(-DMANIAC_LINUX)
endif()

add_subdirectory(Lucid)
add_subdirectory(Maniac)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)