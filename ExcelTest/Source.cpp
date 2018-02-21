#include <conio.h>
#include <time.h>


#include "DateTime.h"
#include "WorkTime.h"
#include "WorkDay.h"
#include "WorkMonth.h"
#include "TimeReport.h"

int main()
{
	srand(time(NULL));

	WorkMonth* wm = new WorkMonth();
	std::cout << *wm << "\n";

	while (_getch())
	{
		for (size_t i = 0; i < 50; i++)
		{
			std::cout << "\n";
		}

		wm = new WorkMonth();
		std::cout << *wm << "\n";

		TimeReport* tmr = new TimeReport();

	}

	
}