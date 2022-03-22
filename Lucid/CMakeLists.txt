add_executable(Lucid main.cpp)

include_directories(../Maniac)

target_link_libraries(Lucid Maniac)