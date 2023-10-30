#pragma once
#include "MessageContent.h"

struct MessageStruct {
	const String name;
	const String messages;
};

class MessageReader
{
	TextReader reader_;
	String current_line_;
public:
	MessageReader();
	MessageStruct readMessageOne();
	Array<MessageStruct> readMessageAll();

};
