file(
  GLOB CPPFILES
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  *.cpp)
message(${CPPFILES})
add_library(numbertools SHARED ${CPPFILES})
