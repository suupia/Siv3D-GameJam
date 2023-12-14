#pragma once
#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include "../MessageBox/JSONDialogueReader.h"


TEST_CASE("JSONDialogueReader read JSON file correctly")
{
	auto jsonReader = JSONDialogueReader(U"texts/test/sc_test_0.json");
	auto dialogueInfos = jsonReader.read_dialogues();

	auto dialogueInfo = dialogueInfos.at(0);

	CHECK(dialogueInfo.messages.at(0).name == U"Taro");
	CHECK(dialogueInfo.messages.at(0).message == U"Hello! I'm Taro.");

	CHECK(dialogueInfo.messages.at(0).name == U"Hanako");
	CHECK(dialogueInfo.messages.at(0).message == U"Hi! I'm Hanako.");

	CHECK(dialogueInfo.messages.at(0).name == U"Taro");
	CHECK(dialogueInfo.messages.at(0).message == U"Nice to meet you.");

}
