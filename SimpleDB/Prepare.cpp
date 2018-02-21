#include "Prepare.h"


Prepare::Prepare()
{
}


Prepare::~Prepare()
{
}

PrepareResult Prepare::statement(
	InputBuffer* inputBuffer, 
	Statement* statement)
{
	if (inputBuffer->isEqual("INSERT")
		|| inputBuffer->isEqual("insert"))
	{
		statement->m_type.setInsert();
		return PREPARE_SUCCESS;
	}
	if (inputBuffer->isEqual("SELECT") 
		|| inputBuffer->isEqual("select"))
	{
		statement->m_type.setSelect();
		return PREPARE_SUCCESS;
	}

	return PREPARE_UNRECOGNIZED_STATEMENT;
}