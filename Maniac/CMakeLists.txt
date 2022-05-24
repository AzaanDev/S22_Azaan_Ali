set(HEADER_FILES
		Maniac.h
		ManiacApp.h
		ManiacUtilities.h
		Window.h
		WindowOS.h
		specificGLFW/GLFWWindow.h
		Sprite.h
		Shader.h
		Render.h
		SpriteImplementation.h
		ShaderImplementation.h
		RenderImplementation.h
		specificGLFW/OpenGLRenderer.h
		specificGLFW/OpenGLShader.h
		specificGLFW/OpenGLSprite.h
		Events.h
		KeyCodes.h
		)
		
set(SOURCES_FILES 
		ManiacApp.cpp
		Window.cpp
		specificGLFW/GLFWWindow.cpp
		Sprite.cpp
		Shader.cpp
		Render.cpp
		specificGLFW/OpenGLRenderer.cpp
		specificGLFW/OpenGLShader.cpp
		specificGLFW/OpenGLSprite.cpp
		Events.cpp
		)

add_library(Maniac SHARED ${HEADER_FILES} ${SOURCES_FILES})

add_definitions(-DMANIAC_LIB)
add_definitions(-DMANIAC_DEBUG)
add_definitions(-DMANIAC_OPENGL)

include_directories(../glfw/include)
include_directories(../Maniac)
include_directories(../stbi)
include_directories(../glad/include)

target_precompile_headers(Lucid PRIVATE pch.h)

target_link_libraries(Maniac glfw glad stbi)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Maniac)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)