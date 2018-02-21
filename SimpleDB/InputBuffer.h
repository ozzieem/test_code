#pragma once

#include <string>

class InputBuffer
{
public:
	std::string m_buffer;
	size_t m_inputLength;

	InputBuffer();

	bool isEqual(std::string str);

};