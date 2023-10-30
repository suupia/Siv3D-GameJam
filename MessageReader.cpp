# include <Siv3D.hpp> // OpenSiv3D v0.6.11
#include "stdafx.h"
#include "MessageReader.h"

namespace
{
	MessageStruct ConvertToMessageStruct(const String& name, const String& messages)
	{
		return MessageStruct{ name, messages };
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
	String line;

	reader_.readLine(line);
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
}

Array<MessageStruct> MessageReader::readMessageAll()
{
	Array<MessageStruct> result;

	Array<String> lines; // Destination of read strings

	reader_.readLines(lines);

	for(auto line: lines)
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
			result.push_back( MessageStruct{ name, messages });
		}
	}
	return result;
}
