# include <Siv3D.hpp> // OpenSiv3D v0.6.11
#include "stdafx.h"
#include "MessageReader.h"

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

MessageStruct MessageReader::getMessageStruct()
{
	String name;
	String messages;

	String line;

	reader_.readLine(line);
	if(line.starts_with(U"$"))
	{
		name = line.substr(1);
		while (line)
		{
			reader_.readLine(line);
			messages += line + U"\n";
		}
		// erase the last "\n"
		messages.pop_back();messages.pop_back();
	}
	return MessageStruct{ name, messages };
}
