file(
  GLOB SUBDIRS
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  *)
foreach(SUBDIR ${SUBDIRS})
  if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})
    # add_subdirectory(${SUBDIR})
    add_executable(${SUBDIR} ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/problem.cpp
                             ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/main.cpp)
    # 将可执行文件放到一个单独的 bin 目录中
    set_target_properties(${SUBDIR} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                               ${CMAKE_BINARY_DIR}/bin)
    target_precompile_headers(${SUBDIR} PRIVATE
                              ${CMAKE_SOURCE_DIR}/include/iostream_wrapper.h)
    # 检查是否存在 config.cmake 文件
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/config.cmake)
      include(${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/config.cmake)
      # 如果 config.cmake 中定义了需要链接的库，就进行链接
      if(TARGET_LIBS)
        target_link_libraries(${SUBDIR} ${TARGET_LIBS})
      endif()
    endif()
  endif()
endforeach()
