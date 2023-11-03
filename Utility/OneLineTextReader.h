#pragma once

class OneLineTextReader
{
public:
	OneLineTextReader(const String& path);
	Array<String> readOneLineAll();
private:
	TextReader reader_;
	Array<String> lines_; // Destination of read strings
};
