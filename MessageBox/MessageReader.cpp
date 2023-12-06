# include <Siv3D.hpp> // OpenSiv3D v0.6.11
#include "../stdafx.h"
#include "MessageReader.h"

MessageReader::MessageReader(const String& path) : reader_{path}
{
	// If the file cannot be opened
	if (not reader_)
	{
		// throw an error
		throw Error{ U"Failed to open `sc_prologue.txt`" };
	}

	// Read it just once to prevent the mistakes that come from reading it multiple times !!
	reader_.readLines(lines_);
}

Optional<MessageStruct> MessageReader::PopOneChunk()
{
	if(lines_.empty()) return none;

	while (true)
	{
		if(lines_.front().starts_with(U"$")) break;
		lines_.pop_front();
		if(lines_.size() <= 0) return  none;
	}

	assert(lines_.front().starts_with(U"$"));

	const String name = lines_.front().substr(1);
	lines_.pop_front();

	// if there is no message
	if(lines_.empty()) return none;

	String messages;
	while (true)
	{
		// reach the end of the file
		if(lines_.empty())break;
		if(lines_.front() == U"" ) break;
		if(lines_.front().starts_with(U"$")) break;
		const auto message_line = lines_.front();
		lines_.pop_front();

		messages += message_line+ U"\n";
	}
	// remove the last line break
	messages.pop_back();
	return MessageStruct{name, messages};

}

MessageStruct MessageReader::readMessageOne()
{
	if(const auto chunk= PopOneChunk(); chunk)
	{
		return *chunk;
	}
	else
	{
		throw Error{ U"Failed to read a message" };
	}
}

Array<MessageStruct> MessageReader::readMessageAll()
{
	Array<MessageStruct> result;

	MessageStruct message_struct;
	while (true)
	{
		if(auto chunk = PopOneChunk(); chunk)
		{
			result.push_back(*chunk);
		}else
		{
			break;
		}
	}

	return result;
}

