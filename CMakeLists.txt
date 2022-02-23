cmake_minimum_required(VERSION 3.10.0)

# change accordingly!
project(CHANGE_ME_I_M_A_TEMPLATE_PROJECT VERSION 0.0.1) 

# build release by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# set to OFF to disable build of benchmark lib and benchmarks
set(ENABLE_BENCHMARK_BUILD ON)

if(ENABLE_BENCHMARK_BUILD)
  # disable building tests for benchmark
  set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
  add_subdirectory("ext/benchmark")
endif()

add_subdirectory("ext/googletest")

add_subdirectory("test")