#include "WorkTime.h"

#include <random>
#include <string>

WorkTime::WorkTime(long startHour, long endHour, long addTime)
{
	minuteOptions.push_back(00);
	minuteOptions.push_back(30);

	hour = generateHourBetween(startHour, endHour, addTime);
	minute = generateMinute();
}

WorkTime::~WorkTime()
{
}

long WorkTime::generateHourBetween(long start, long end, long addTime)
{
	/* generate hour between "start" and "end" then add "addTime": */
	return (rand() % (end - start + 1) + start) + addTime;
	
}

long WorkTime::generateMinute()
{
	/* pick one of the available minute options */
	return minuteOptions.at(rand() % minuteOptions.size());
}

std::ostream & operator<<(std::ostream & os, const WorkTime & wt)
{
	os << wt.hour << ":" << (wt.minute == 0 ? "00" : std::to_string(wt.minute));
	return os;
}
