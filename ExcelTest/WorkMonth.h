#pragma once

#include <vector>
#include <iostream>

#include "WorkDay.h"

namespace {
	const long MIN_NUM_OF_WEEKENDS = 8;
	const long MAX_TOTAL_HOURS = 34;
	const long MAX_TOTAL_MINUTES = MAX_TOTAL_HOURS * 60;
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

	void generateDay();

	void addTotalHours(WorkDay& wd);

	void addDay(WorkDay& wd);

	void reset();

	friend std::ostream& operator<<(std::ostream & os, const WorkMonth& wm);
};

