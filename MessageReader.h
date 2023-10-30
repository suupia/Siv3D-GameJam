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
	[[nodiscard]]
	MessageStruct readMessageOne();
	[[nodiscard]]
	Array<MessageStruct> readMessageAll();

};
