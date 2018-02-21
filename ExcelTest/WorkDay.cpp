#include "WorkDay.h"

#include <random>
#include <assert.h>

WorkDay::WorkDay()
	: totalTime(0)
	, totalEveningTime(0)
	, totalNightTime(0)
	, totalWeekendTime(0)
	, totalWeekendNightTime(0)
{
	startTime = new WorkTime(HARD_START_TIME, HARD_END_TIME);
	do
	{
		endTime = new WorkTime(MIN_WORK_DURATION, MAX_WORK_DURATION, startTime->hour);
	} while (endTime->hour > 23);
	

	date = new DateTime(1); // random date

	setTotalTime();
	setTotalEveningTime();
	setTotalNightTime();
	setTotalWeekendTime();
}


WorkDay::~WorkDay()
{
}

void WorkDay::setTotalTime()
{
	double diff = (endTime->hour - startTime->hour) * 60;

	if (startTime->minute == 30)
	{
		diff -= 30;
	}
	if (endTime->minute == 30)
	{
		diff += 30;
	}
	diff /= 60;
	assert(!(diff <= 0)); // diff should always be gt 0

	totalTime = diff;
}

void WorkDay::setTotalEveningTime()
{
	double diff = 0;

	if (endTime->hour >= EVENING_TIME_START)
	{
		diff = (endTime->hour - EVENING_TIME_START) * 60;
		if (startTime->minute == 30 && startTime->hour > EVENING_TIME_START)
		{
			diff -= 30;
		}
		if (endTime->minute == 30 && endTime->hour < EVENING_TIME_END)
		{
			diff += 30;
		}
		if (endTime->hour > EVENING_TIME_END)
		{
			diff -= 60;
		}
	}
	totalEveningTime = diff < 0 ? 0 : diff / 60;
}

void WorkDay::setTotalNightTime()
{
	double diff = 0;

	if (endTime->hour >= EVENING_TIME_END)
	{
		diff = (endTime->hour - NIGHT_TIME_START) * 60;

		if (endTime->minute == 30)
		{
			diff += 30;
		}
	}
	totalNightTime = diff < 0 ? 0 : diff / 60;
}

void WorkDay::setTotalWeekendTime()
{
	// Weekend Friday 19 - Mon 07
	// Here only Friday after 19 and both saturday and sunday is added
	double weekendTime = 0;
	if (date->weekday == 4)
	{
		if (   startTime->hour >= WEEKEND_TIME_START
			|| endTime->hour >= WEEKEND_TIME_START)
		{
			weekendTime += totalEveningTime;
			weekendTime += totalNightTime;
			totalEveningTime = 0;
			totalNightTime = 0;
		}
	}
	if (date->isWeekend())
	{
		weekendTime += totalTime;
		totalWeekendNightTime += totalNightTime;
		totalWeekdayTime = 0;
		totalEveningTime = 0;
		totalNightTime = 0;
	}
	totalWeekendTime = weekendTime;
}

std::ostream & operator<<(std::ostream & os, const WorkDay& wd)
{
	os << *wd.date << "| W?:" << wd.date->isWeekend()
		<< "| " << *wd.startTime << "-" << *wd.endTime << "\t"
		<< "| Time:" << wd.totalTime << "\t"
		<< "| Evening:" << wd.totalEveningTime << "\t"
		<< "| Night:" << wd.totalNightTime << "\t"
		<< "| Weekend:" << wd.totalWeekendTime << "\t"
		<< "| WNight:" << wd.totalWeekendNightTime;
	return os;
}
