#include <iostream>
#include <string>

#include "InputBuffer.h"
#include "MetaCommand.h"
#include "Statement.h"
#include "Prepare.h"

void printPrompt()
{
	std::cout << "db > ";
}

void readInput(InputBuffer* inpBuffer)
{
	std::getline(std::cin, inpBuffer->m_buffer);
}

int main()
{
	InputBuffer* inputBuffer = new InputBuffer();
	MetaCommand* metaCommand = new MetaCommand();
	Statement* statement= new Statement();
	Prepare* prepare = new Prepare();

	while (true)
	{
		printPrompt();

		readInput( inputBuffer );

		if ( inputBuffer->m_buffer.at( 0 ) == '.' )
		{
			switch ( metaCommand->read( inputBuffer ) )
			{
			case META_COMMAND_SUCCESS:
				continue;
			case META_COMMAND_UNRECOGNIZED_COMMAND:
				std::cout << "Unrecognized command " << inputBuffer->m_buffer << "\n";
				continue;
			default:
				break;
			}
		}

		switch ( prepare->statement( inputBuffer, statement ) )
		{
		case PREPARE_SUCCESS:
			break;
		case PREPARE_UNRECOGNIZED_STATEMENT:
			std::cout << "Unrecognized keyword at start of " << inputBuffer->m_buffer << "\n";
			continue;
		default:
			break;
		}

		statement->execute();
		printf("Executed.\n");
	}
}

// Stopped at part3
// https://cstack.github.io/db_tutorial/parts/part3.html

