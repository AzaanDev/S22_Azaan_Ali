set(HEADER_FILES
		Maniac.h
		ManiacApp.h
		ManiacUtilities.h
		Window.h
		WindowOS.h
		specificGLFW/GLFWWindow.h
		)
		
set(SOURCES_FILES 
		ManiacApp.cpp
		Window.cpp
		specificGLFW/GLFWWindow.cpp
		)

add_library(Maniac SHARED ${HEADER_FILES} ${SOURCES_FILES})

add_definitions(-DMANIAC_LIB)
add_definitions(-DMANIAC_DEBUG)

include_directories(../glfw/include)
include_directories(../Maniac)

target_precompile_headers(Lucid PRIVATE pch.h)

target_link_libraries(Maniac glfw)