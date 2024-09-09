file(
  GLOB LIBFILES
  ${CMAKE_CURRENT_SOURCE_DIR}
  *.cpp)
set(LIBFILES ${LIBFILES} CACHE STRING "Globbed lib source files")
add_library(numbertools SHARED ${LIBFILES})
