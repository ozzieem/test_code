#include "InputBuffer.h"

InputBuffer::InputBuffer::InputBuffer()
	: m_buffer()
	, m_inputLength(0)
{
}

bool InputBuffer::isEqual(std::string str)
{
	return !m_buffer.compare(str);
}
