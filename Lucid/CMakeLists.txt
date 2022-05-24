set(HEADER_FILES
		Entity.h
		LucidApp.h
)

set(SOURCE_FILES
		Entity.cpp
		LucidApp.cpp
		main.cpp
)

add_executable(Lucid ${HEADER_FILES} ${SOURCE_FILES})

include_directories(../Maniac)

target_link_libraries(Lucid Maniac)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Lucid)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)