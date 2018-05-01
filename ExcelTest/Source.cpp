#include <conio.h>
#include <time.h>


#include "DateTime.h"
#include "WorkTime.h"
#include "WorkDay.h"
#include "WorkMonth.h"
#include "TimeReport.h"

const short KEY_ESC = 27;

int main()
{
	srand(time(NULL));

	WorkMonth* wm = new WorkMonth();
	std::cout << *wm << "\n";

	do
	{
		for (size_t i = 0; i < 50; i++)
		{
			std::cout << "\n";
		}

		wm = new WorkMonth();
		std::cout << *wm << "\n";

		//TimeReport* tmr = new TimeReport();

	} while (_getch() != KEY_ESC);
}