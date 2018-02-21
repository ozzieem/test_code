#include "DateTime.h"

#include <ctime>
#include <string>

DateTime::DateTime(long random)
{
	time_t t = time(0);
	struct tm* now = new tm();
	localtime_s(now, &t);

	year = now->tm_year + 1900;
	month = now->tm_mon + 1;

	if (random)
	{
		now->tm_mday = getRandomDay();
		mktime(now);
	}

	day = now->tm_mday;
	weekday = now->tm_wday;
}

DateTime::~DateTime()
{
}

bool DateTime::isWeekend()
{
	const unsigned weekends = (1 << 5) | (1 << 6);
	if ( (1 << weekday) & weekends )
	{
		return true;
	}
	return false;
}

long DateTime::getRandomDay()
{
	/* hardcoded for now */
	long firstDay = 1, lastDay = 30;
	return (rand() % (lastDay - firstDay + 1) + firstDay);
}

std::ostream& operator<<(std::ostream & os, const DateTime & dt)
{
	os << dt.year << "-" << dt.month << "-" <<
		(dt.day < 10 ? "0" : "") << dt.day << " Weekday:" << dt.weekday;

	return os;
}
