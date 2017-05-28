#pragma once
#include <chrono>

class Stopwatch
{
	std::chrono::steady_clock::time_point begin;
public:
	void start();
	double check();
};