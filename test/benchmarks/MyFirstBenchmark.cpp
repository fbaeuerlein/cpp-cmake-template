#include <benchmark/benchmark.h>
#include <vector>

void SomeFunction()
{
    std::vector<size_t> v;
    for ( size_t i = 0; i < 10000; ++i )
    {
        v.push_back(i);
    }
    v.clear();
}

static void BM_SomeFunction(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    SomeFunction();
  }
}
// Register the function as a benchmark
BENCHMARK(BM_SomeFunction);
// Run the benchmark
BENCHMARK_MAIN();