add_subdirectory("unittests")

# if benchmark build is enabled, also build subdirectory
if(ENABLE_BENCHMARK_BUILD)
    add_subdirectory("benchmarks")
endif()