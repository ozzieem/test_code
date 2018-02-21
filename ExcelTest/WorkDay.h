#pragma once

#include "WorkTime.h"
#include "DateTime.h"

namespace {
	const long HARD_START_TIME = 10;
	const long HARD_END_TIME = 18;

	const long MIN_WORK_DURATION = 3;
	const long MAX_WORK_DURATION = 7;

	const long EVENING_TIME_START = 19;
	const long EVENING_TIME_END = 22;

	const long NIGHT_TIME_START = 22;
	const long NIGHT_TIME_END = 24;

	const long WEEKEND_TIME_START = 19;
	const long WEEKEND_TIME_END = 24;
}


class WorkDay
{
public:
	WorkTime* startTime;
	WorkTime* endTime;

	DateTime* date;

	double totalTime;
	double totalWeekdayTime;
	double totalEveningTime;
	double totalNightTime;
	double totalWeekendTime;
	double totalWeekendNightTime;

	/* only works if taking the difference between 0 - 23, not night hours*/
	void setTotalTime();
	void setTotalEveningTime();
	void setTotalNightTime();
	void setTotalWeekendTime();

	WorkDay();
	~WorkDay();

	friend std::ostream& operator<< (std::ostream& os, const WorkDay& wd);
};

