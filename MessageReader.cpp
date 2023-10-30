# include <Siv3D.hpp> // OpenSiv3D v0.6.11
#include "stdafx.h"
#include "MessageReader.h"

namespace
{
	MessageStruct ReadOneChunk(TextReader& reader_, String line)
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
			messages.pop_back();messages.pop_back();
			return MessageStruct{ name, messages };
		}
		else
		{
			throw Error{ U"Invalid format" };
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
	return  ReadOneChunk(reader_, line);
}

Array<MessageStruct> MessageReader::readMessageAll()
{
	Array<MessageStruct> result;
	Array<String> lines; // Destination of read strings
	reader_.readLines(lines);
	for(const auto line: lines)
	{
		result.push_back(ReadOneChunk(reader_,line));
	}
	return result;
}
