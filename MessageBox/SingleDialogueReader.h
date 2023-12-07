#pragma once
#include "MessageStruct.h"

// 1つのファイルから1つの対話を読み込む
class SingleDialogueReader
{
public:
	SingleDialogueReader(const String& path);
	[[nodiscard]]
	Array<MessageStruct> readMessageAll();
private:
	TextReader reader_;
	Array<String> lines_; // Destination of read strings
	Optional<MessageStruct>  PopOneChunk();

};
