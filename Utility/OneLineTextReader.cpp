#include "../stdafx.h"
#include "OneLineTextReader.h"

// public
OneLineTextReader::OneLineTextReader(const String& path) : reader_(path)
{
	// If the file cannot be opened
	if (not reader_)
	{
		// throw an error
		throw Error{ U"Failed to open `{}`"_fmt(path) };
	}

	// Read it just once to prevent the mistakes that come from reading it multiple times !!
	reader_.readLines(lines_);
}

Array<String> OneLineTextReader::readOneLineAll()
{
	Array<String> result;

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

// private
Optional<String> OneLineTextReader::PopOneChunk()
{
	String chunk;

	if(lines_.empty()) return none;

	while (true)
	{
		if(lines_.front() != U"") break;
		lines_.pop_front();
		if(lines_.size() <= 0) return  none;
	}
	assert(lines_.front() != U"");

	while (true)
	{
		if(lines_.empty()) return chunk;
		if(lines_.front() == U"")
		{
			lines_.pop_front();
			break;
		}
		chunk += lines_.front() + U"\n";
		lines_.pop_front();
	}
	// erase the last "\n"
	chunk.pop_back();

	return chunk;

}
