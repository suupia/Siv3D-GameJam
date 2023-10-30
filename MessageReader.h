#pragma once

class MessageReader
{
	TextReader reader_;
	String current_line_;
public:
	MessageReader();
	String getMessage();

};
