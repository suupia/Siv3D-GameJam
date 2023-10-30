# include <Siv3D.hpp> // OpenSiv3D v0.6.11
#include "stdafx.h"
#include "MessageReader.h"

namespace
{
	Optional<MessageStruct> ReadOneChunk(TextReader& reader_, String line)
	{
		if(line.starts_with(U"$"))
		{
			const String name = line.substr(1);
			String messages;
			while (line)
			{
				reader_.readLine(line);
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
	Array<String> lines; // Destination of read strings
	reader_.readLines(lines);
	for(const auto line: lines)
	{
		if(const auto message_struct = ReadOneChunk(reader_, line); message_struct)
		{
			result.push_back(*message_struct);
		}
	}
	return result;
}
