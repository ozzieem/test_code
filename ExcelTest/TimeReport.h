#pragma once

#include "libxl.h"
#include "WorkMonth.h"

using namespace libxl;

namespace File {
	const std::string TIME_REPORT_PATH = "OriginalTimeReport.xls";
}

namespace Cell {

	struct Cell
	{
		long row;
		long col;

		Cell(long alphNum, long num)
			: row(num - 1)
			, col(alphNum - 1)
		{
		}
	};

	const Cell DATE_START(2, 20);
	const Cell DATE_END(2, 50);

	const Cell TOTAL_WORKING_TIME(9, 51);
	const Cell TOTAL_WEEKDAY_EVENING_TIME(16, 51);
	const Cell TOTAL_WEEKDAY_NIGHT_TIME(17, 51);
	const Cell TOTAL_WEEKEND_TIME(20, 51);
	const Cell TOTAL_WEEKEND_NIGHT_TIME(22, 51);

	const Cell TOTAL_WORKING_DAYS(9, 53);

	const Cell YEAR_MONTH(2, 10);
	const Cell NAME(8, 10);
	const Cell PERSON_NUMBER(21, 10);
	const Cell ADDRESS(4, 12);
	const Cell POST_NUMBER(4, 12);
}

class TimeReport
{
private:

	Book* book;
	Sheet* sheet;
	WorkMonth* workMonth;

public:
	TimeReport();
	~TimeReport();

	void insertDays();
	long open();
	void save();
};

