
add_subdirectory(codegen)
add_subdirectory(builder)
add_subdirectory(sc_dumper)

#if(${SC_BUILD_TESTS})
  add_subdirectory(unit_tests)
#endif ()