# include <Siv3D.hpp> // OpenSiv3D v0.6.11
#include "stdafx.h"
#include "MessageReader.h"

namespace
{
	Optional<MessageStruct> ReadOneChunk(TextReader& reader, String& line)
	{
		if(line.starts_with(U"$"))
		{
			const String name = line.substr(1);
			String messages;
			while (line)
			{
				Print << U"ReadOneChunk before line: " << line;

				reader.readLine(line);
				Print << U"ReadOneChunk after line: " << line;

				messages += line + U"\n";
			}
			// erase the last "\n"
			messages.pop_back();
			return MessageStruct{ name, messages };
		}
		else
		{
			return none;
		}
	}
}

MessageReader::MessageReader()
{
	reader_ =  TextReader{ U"texts/sc_prologue.txt" };
	// If the file cannot be opened
	if (not reader_)
	{
		// throw an error
		throw Error{ U"Failed to open `sc_prologue.txt`" };
	}
}

Optional<MessageStruct> MessageReader::PopOneChunk()
{
	while (true)
	{
		if(lines_.front().starts_with(U"$")) break;
		lines_.pop_front();
		if(lines_.size() <= 0) return  none;
	}

	assert(lines_.front().starts_with(U"$"));

	const String name = lines_.front().substr(1);
	lines_.pop_front();

	String messages;
	while (true)
	{
		if(lines_.empty()) return none;
		if(lines_.front().starts_with(U"$")) break;
		auto message_line = lines_.front();
		lines_.pop_front();

		messages += message_line + U"\n";
	}
	// erase the last "\n"
	messages.pop_back();
	return MessageStruct{name, messages};

}

MessageStruct MessageReader::readMessageOne()
{
	String line; // Destination of read strings
	reader_.readLine(line);
	if(const auto message_struct = ReadOneChunk(reader_, line); message_struct)
	{
		return *message_struct;
	}
	else
	{
		throw Error{ U"Failed to read a message" };
	}
}

Array<MessageStruct> MessageReader::readMessageAll()
{
	Array<MessageStruct> result;
	reader_.readLines(lines_);
	Print << U"lines" << lines_;

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

