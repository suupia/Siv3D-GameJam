#pragma once
#include "SingleDialogueReader.h"

// 1つのファイルから複数の対話を読み込む
class MultipleDialogueReader
{
public:
	MultipleDialogueReader(const String& path);
	[[nodiscard]]
	Array<DialogueString> readMessageAll();
private:
	TextReader reader_;
	Array<String> lines_; // Destination of read strings
	Optional<DialogueString> read_dialogue_string();
	Optional<MessageString>  read_message_string();
};
