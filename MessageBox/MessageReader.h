#pragma once

struct MessageStruct {
	const String name;
	const String messages;
};

class MessageReader
{
	TextReader reader_;
	Array<String> lines_; // Destination of read strings

	Optional<MessageStruct>  PopOneChunk();
public:
	MessageReader(const String& path);
	[[nodiscard]]
	MessageStruct readMessageOne();
	[[nodiscard]]
	Array<MessageStruct> readMessageAll();

};
