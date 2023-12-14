#pragma once
#include "DialogueInfo.h"

class JSONDialogueReader
{
public:
	JSONDialogueReader(String path);
	[[nodiscard]]
	Array<DialogueInfo> read_dialogues();
private:
	String path_;
};
