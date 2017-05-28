#include "Stopwatch.h"

void Stopwatch::start()
{
	begin = std::chrono::steady_clock::now();
}

double Stopwatch::check()
{
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	long long int count = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	begin = end;
	return ((double)count) / 1000.0;
}