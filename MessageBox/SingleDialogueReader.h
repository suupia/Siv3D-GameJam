#pragma once

struct MessageStruct {
	const String name;
	const String messages;
};

// 1つのファイルから1つの対話を読み込む
class SingleDialogueReader
{
public:
	SingleDialogueReader(const String& path);
	[[nodiscard]]
	MessageStruct readMessageOne();
	[[nodiscard]]
	Array<MessageStruct> readMessageAll();
private:
	TextReader reader_;
	Array<String> lines_; // Destination of read strings
	Optional<MessageStruct>  PopOneChunk();

};
