#pragma once

class IdentifyTextReader
{
public:
	IdentifyTextReader(const String& path);
	Array<String> readIdentifyTextAll();
private:
	TextReader reader_;
	Array<String> lines_; // Destination of read strings
};
