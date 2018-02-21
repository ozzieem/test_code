#pragma once

#include <iostream>

class DateTime
{
public:
	long year;
	long month;
	long day;

	long weekday;

	DateTime(long random);
	~DateTime();

	bool isWeekend();
	long getRandomDay();
	friend std::ostream& operator<<(std::ostream& os, const DateTime& dt);
};

