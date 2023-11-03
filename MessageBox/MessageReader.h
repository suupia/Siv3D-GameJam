#pragma once

struct MessageStruct {
	const String name;
	const String messages;
};

class MessageReader
{
public:
	MessageReader(const String& path);
	[[nodiscard]]
	MessageStruct readMessageOne();
	[[nodiscard]]
	Array<MessageStruct> readMessageAll();
private:
	TextReader reader_;
	Array<String> lines_; // Destination of read strings
	Optional<MessageStruct>  PopOneChunk();

};
