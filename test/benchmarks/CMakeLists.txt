enable_testing()

include_directories("../../ext/benchmark/include")

add_executable(MyFirstBenchmark MyFirstBenchmark.cpp)
target_link_libraries(MyFirstBenchmark benchmark)
