#pragma once

#include "Inputbuffer.h"
#include "Statement.h"

typedef enum PrepareResult
{
	PREPARE_SUCCESS,
	PREPARE_UNRECOGNIZED_STATEMENT
};

class Prepare
{
public:
	Prepare();
	~Prepare();

	PrepareResult statement(
		InputBuffer * inputBuffer, 
		Statement * statement);

	

};

