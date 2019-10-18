#pragma once
#include "pch.h"
#include "Util.hpp"

static bool TimeZeroCalculated = false;
static std::chrono::system_clock::time_point time0;

double Util::GetTimeStamp()
{
	if (!TimeZeroCalculated)
	{
		time0 = std::chrono::system_clock::now();
		TimeZeroCalculated = true;
	}
	auto tstamp = std::chrono::system_clock::now() - time0;

	long long delta = std::chrono::duration_cast<std::chrono::nanoseconds>(tstamp).count();

	return delta * 0.000000001;
}