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

String MessageReader::getMessage()
{
	String result_line;
	String line;

	reader_.readLine(line);
	if(line.starts_with(U"$"))
	{
		result_line = U"[" + line.substr(1) + U"]\n";
		while (line)
		{
			reader_.readLine(line);
			result_line += line + U"\n";
		}
		// erase the last "\n"
		result_line.pop_back();result_line.pop_back();
	}
	return result_line;
}
