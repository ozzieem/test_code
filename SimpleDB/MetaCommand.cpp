#include "MetaCommand.h"



MetaCommand::MetaCommand()
{
}


MetaCommand::~MetaCommand()
{
}

MetaCommandResult MetaCommand::read(InputBuffer* inputBuffer)
{
	if (inputBuffer->isEqual(".exit"))
	{
		exit(EXIT_SUCCESS);
	}
	return META_COMMAND_UNRECOGNIZED_COMMAND;
}
