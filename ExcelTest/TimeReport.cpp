#include "TimeReport.h"


TimeReport::TimeReport()
{
	if (!open())
	{
		std::cout << "Error:" << book->errorMessage();

		return;
	}

	//if (book)
	//{
	//	sheet->writeNum(18, 8, 15);
	//	sheet->writeNum(21, 8, 4);
	//}
	//		
	
}


TimeReport::~TimeReport()
{
}

void TimeReport::insertDays()
{
}

long TimeReport::open()
{
	book = xlCreateBook();
	//book->load(File::TIME_REPORT_PATH.c_str());
	book->load("gggg.xls");

	if (book)
	{
		return 1;
	}

	std::cout << "Error:" << book->errorMessage();
	return 0;
}

void TimeReport::save()
{
	book->save(File::TIME_REPORT_PATH.c_str());
	book->release();
}