#pragma once
#include "DialogueString.h"

class JSONDialogueReader
{
public:
	JSONDialogueReader(const String& path);
	[[nodiscard]]
	Array<DialogueString> readDialogueAll();
};
