#include "WorkMonth.h"

#include <algorithm>



namespace {
	bool sortByDay(const WorkDay &lhs, const WorkDay &rhs) { return lhs.date->day < rhs.date->day; }
}

WorkMonth::WorkMonth()
	: totalHours(0)
	, totalEveningHours(0)
	, totalNightHours(0)
	, totalWeekendHours(0)
	, totalDays(0)
	, totalWeekdays(0)
	, totalWeekends(0)
{
	createDays();
}

WorkMonth::WorkMonth(long desiredDays)
	: totalHours(0)
	, totalEveningHours(0)
	, totalNightHours(0)
	, totalWeekendHours(0)
	, totalDays(0)
	, totalWeekdays(0)
	, totalWeekends(0)
{
	do
	{
		reset();
		createDays();
		printf("Generating...\r");
	} while (totalDays >= desiredDays);
}


WorkMonth::~WorkMonth()
{
}

void WorkMonth::createDays()
{
	do
	{
		generateDay();
	} while (totalHours <= MAX_TOTAL_HOURS );

	std::sort(days.begin(), days.end(), sortByDay);
}

void WorkMonth::generateDay()
{
	WorkDay* wd = new WorkDay();

	long totalWeekends = 0;

	for(WorkDay& workDay : days)
	{
		if (wd->date->day == workDay.date->day)
		{
			// date exists, return early
			return;
		}
		workDay.date->isWeekend() ? totalWeekends++ : 0;
	}

	// Check to see if enough weekends have been generated
	if (totalWeekends < MIN_NUM_OF_WEEKENDS && !wd->date->isWeekend())
	{
		return;
	}

	addDay(*wd);
}

void WorkMonth::addTotalHours(WorkDay& wd)
{
	if (wd.date->isWeekend())
	{
		totalWeekendHours += wd.totalWeekendTime;
		totalWeekendNightHours += wd.totalWeekendNightTime;
	}
	else
	{
		totalHours += wd.totalTime;
		totalEveningHours += wd.totalEveningTime;
		totalNightHours += wd.totalNightTime;
	}
}

void WorkMonth::addDay(WorkDay& wd)
{
	days.push_back(wd);
	totalDays++;
	addTotalHours(wd);

	wd.date->isWeekend() ? totalWeekends++ : totalWeekdays++;
}

void WorkMonth::reset()
{
	totalHours = 0;
	totalEveningHours = 0;
	totalNightHours = 0;
	totalWeekendHours = 0;
	totalDays = 0;
	totalWeekdays = 0;
	totalWeekends = 0;
	days.clear();
}

std::ostream & operator<<(std::ostream & os, const WorkMonth& wm)
{
	for(const WorkDay& wd : wm.days)
	{
		os << wd << "\n";
	}
	os << "| Total:\n";
	os << "| MonthHours:       \t" << wm.totalHours << "\n";
	os << "| MonthEveningHours:\t" << wm.totalEveningHours << "\n";
	os << "| MonthNightHours:  \t" << wm.totalNightHours << "\n";
	os << "| MonthWeekendHours:\t" << wm.totalWeekendHours << "\n";
	os << "| MonthWeekendNightHours:\t" << wm.totalWeekendNightHours << "\n";
	os << "| WorkDays:" << wm.totalDays << "\n";
	os << "| Weekdays:" << wm.totalWeekdays << "\n";
	os << "| Weekends:" << wm.totalWeekends << "\n";
	return os;
}

