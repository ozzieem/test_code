#pragma once

#include <vector>
#include <iostream>

#include "WorkDay.h"

namespace {
	const long MIN_NUM_OF_WEEKENDS = 4;
	const long MAX_TOTAL_MINUTES = 2140;
	const long MAX_TOTAL_HOURS = MAX_TOTAL_MINUTES / 60;
}

class WorkMonth
{
public:
	WorkMonth();
	WorkMonth(long days);
	~WorkMonth();

	std::vector<WorkDay> days;

	double totalHours;
	double totalWeekdayHours;
	double totalEveningHours;
	double totalNightHours;
	double totalWeekendHours;
	double totalWeekendNightHours;
	double totalDays;
	double totalWeekdays;
	double totalWeekends;
	
	void createDays();

	bool generateDay();

	void addTotalHours(WorkDay& wd);

	void addDay(WorkDay& wd);

	void reset();

	friend std::ostream& operator<<(std::ostream & os, const WorkMonth& wm);
};

