#pragma once

#include "Inputbuffer.h"

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

	PrepareResult prepareStatement();

	

};

