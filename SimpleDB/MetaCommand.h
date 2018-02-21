#pragma once

#include "InputBuffer.h"

typedef enum MetaCommandResult
{
	META_COMMAND_SUCCESS,
	META_COMMAND_UNRECOGNIZED_COMMAND
};


class MetaCommand
{
public:
	MetaCommand();
	~MetaCommand();

	MetaCommandResult m_result;

	MetaCommandResult read(InputBuffer* inputBuffer);
};

