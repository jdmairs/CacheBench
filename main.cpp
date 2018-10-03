#include <iostream>
#include "RNG.h"
#include <benchmark/benchmark.h>

static void cacheBench(benchmark::State& state) {
	int bytes = 1 << state.range(0);
	// compute how many elements we can fit into this many bytes given that we
	// need 2x to represent both data and indices into the data

	int count = (bytes / sizeof(int)) / 2;
	std::vector<int> v;
	for (auto i : RNG<int>(std::numeric_limits<int>::min(),
		std::numeric_limits<int>::max(), count))
		v.push_back(i);
	std::vector<int> indices;
	for (auto i : RNG<int>(0, count, count))
		indices.push_back(i);

	while (state.KeepRunning())
	{
		long sum = 0;
		for (int i : indices)
			sum += v[i];
		benchmark::DoNotOptimize(sum);
	}

	state.SetBytesProcessed(long(state.iterations() * long(bytes)));
	state.SetLabel(std::to_string(bytes / 1024) + "kb");
}
// Register the function as a benchmark
BENCHMARK(cacheBench)->DenseRange(13,26)->ReportAggregatesOnly(true);

BENCHMARK_MAIN();

