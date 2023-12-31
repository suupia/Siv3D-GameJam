#pragma once
#include "DialogueInfo.h"
#include "MessageInfo.h"

// 1つのファイルから1つの対話を読み込む
class SingleDialogueReader
{
public:
	SingleDialogueReader(const String& path);
	[[nodiscard]]
	DialogueInfo readMessageAll();
private:
	TextReader reader_;
	Array<String> lines_; // Destination of read strings
	Optional<MessageInfo>  PopOneChunk();

};
