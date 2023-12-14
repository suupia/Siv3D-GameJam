#pragma once
#include "SingleDialogueReader.h"

// 1つのファイルから複数の対話を読み込む
class MultipleDialogueReader
{
public:
	MultipleDialogueReader(const String& path);
	[[nodiscard]]
	Array<DialogueInfo> readMessageAll();
private:
	TextReader reader_;
	Array<String> lines_; // Destination of read strings
	Optional<DialogueInfo> read_dialogue_string();
	Optional<MessageInfo>  read_message_string();
};
