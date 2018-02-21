#pragma once

#include <iostream>
#include <vector>

class WorkTime
{
private:

	std::vector<long> minuteOptions;

public:

	WorkTime(long startHour, long endHour, long addTime = 0);
	~WorkTime();

	long hour;
	long minute;

	long generateHourBetween(long start, long end, long addTime = 0);

	long generateMinute();

	friend std::ostream& operator<< (std::ostream& os, const WorkTime& wt);
};

