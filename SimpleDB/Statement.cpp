#include "Statement.h"



Statement::Statement()
{
}


Statement::~Statement()
{
}

void Statement::execute()
{
	switch (m_type.value)
	{
	case STATEMENT_INSERT:
		std::cout << "INSERT\n";
		break;
	case STATEMENT_SELECT:
		std::cout << "SELECT\n";
		break;
	default:
		break;
	}
}
