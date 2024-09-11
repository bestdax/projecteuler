# file( GLOB LIBFILES ${CMAKE_CURRENT_SOURCE_DIR} *.cpp) set(LIBFILES
# ${LIBFILES} CACHE STRING "Globbed lib source files")
add_library(prime SHARED prime.cpp)
add_library(sint SHARED stringint.cpp)
add_library(numutils SHARED numutils.cpp)
