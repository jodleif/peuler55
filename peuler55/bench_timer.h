#pragma once
#include <chrono>
class bench_timer
{
private:
	std::chrono::high_resolution_clock clk;
	std::chrono::time_point<std::chrono::high_resolution_clock> t1;
public:
	bench_timer();
	~bench_timer();
};

