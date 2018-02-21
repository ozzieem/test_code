#pragma once

#include <iostream>
#include <vector>

namespace
{
	enum
	{
		STATEMENT_INSERT,
		STATEMENT_SELECT
	};

	const long COLUMN_USERNAME_SIZE = 32;
	const long COLUMN_EMAIL_SIZE = 255;
}

struct StatementType
{
	long value;

	void setInsert() { value = STATEMENT_INSERT; }
	void setSelect() { value = STATEMENT_SELECT; }
};

typedef struct Row
{
	std::vector<std::string> username;
	std::vector<std::string> email;

	Row()
	{
		username.reserve(COLUMN_USERNAME_SIZE);
		email.reserve(COLUMN_EMAIL_SIZE);
	}
};



class Statement
{
public:
	Statement();
	~Statement();

	StatementType m_type;
	
	Row m_insertRow;

	void execute();
};

