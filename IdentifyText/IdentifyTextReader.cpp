#include "../stdafx.h"
#include "IdentifyTextReader.h"

IdentifyTextReader::IdentifyTextReader(const String& path) : reader_(path)
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

Array<String> IdentifyTextReader::readIdentifyTextAll()
{
	Array<String> result;

	while (true)
	{
		if(lines_.empty()) break;
		result.push_back(lines_.front());
		lines_.pop_front();
	}

	return result;
}
