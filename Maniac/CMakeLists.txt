add_library(Maniac SHARED Maniac.h ManiacApp.h ManiacUtilities.h ManiacApp.cpp)

add_definitions(-DMANIAC_LIB)
add_definitions(-DMANIAC_DEBUG)