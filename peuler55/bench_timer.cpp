#include "bench_timer.h"
#include <iostream>


bench_timer::bench_timer()
{
	t1 = clk.now();
}


bench_timer::~bench_timer()
{
	auto t2 = clk.now();
	auto t3 = t2 - t1;
	auto t4 = std::chrono::duration_cast<std::chrono::milliseconds>(t3);
	std::cout << "Execution took: " << t4.count() << "ms\n";
}
