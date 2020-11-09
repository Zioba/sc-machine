
add_executable(tools-test test.cpp)
target_include_directories(tools-test
  PRIVATE ${SC_MEMORY_SRC}
  PRIVATE ${GLIB2_INCLUDE_DIRS}
  )
target_link_libraries(tools-test sc-core)

add_executable(tools-threading-test test_threading.cpp)
target_include_directories(tools-threading-test
  PRIVATE ${SC_MEMORY_SRC}
  PRIVATE ${GLIB2_INCLUDE_DIRS}
  )
target_link_libraries(tools-threading-test sc-core)

add_subdirectory(sc-dumper)
