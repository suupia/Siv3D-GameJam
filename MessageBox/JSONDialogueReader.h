#pragma once
#include "DialogueInfo.h"

class JSONDialogueReader
{
public:
	JSONDialogueReader(const String& path);
	[[nodiscard]]
	Array<DialogueInfo> readDialogueAll();
};
