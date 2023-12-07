#pragma once
#include "SingleDialogueReader.h"

// 1つのファイルから複数の対話を読み込む
class MultipleDialogueReader
{
public:
	MultipleDialogueReader(const String& path);
	[[nodiscard]]
	MessageStruct readMessageOne();
	[[nodiscard]]
	Array<MessageStruct> readMessageAll();
private:
	TextReader reader_;
	Array<String> lines_; // Destination of read strings
	Optional<MessageStruct>  PopOneChunk();
};
