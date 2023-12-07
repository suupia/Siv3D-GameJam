#pragma once
#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include "../MessageBox/MultipleDialogueReader.h"


TEST_CASE("MultipleDialogue should return words with line breaks separated by")
{
	// auto multiple_dialogue_reader = SingleDialogueReader(U"texts/test/sc_test_0.txt");
	auto multiple_dialogue_reader = MultipleDialogueReader(U"texts/test/MultipleDialogueReaderTest_0.txt");
	const auto dialogue_string = multiple_dialogue_reader.readMessageAll();

	CHECK(dialogue_string.size() == 2);

	CHECK(dialogue_string.at(0).messages.at(0).name == U"Taro");
	CHECK(dialogue_string.at(0).messages.at(0).messages == U"Hi! I'm Taro.");

	CHECK(dialogue_string.at(0).messages.at(1).name == U"Hanako");
	CHECK(dialogue_string.at(0).messages.at(1).messages == U"Hi! I'm Hanako.");

	CHECK(dialogue_string.at(1).messages.at(0).name == U"Taro");
	CHECK(dialogue_string.at(1).messages.at(0).messages == U"I like soccer.");

	CHECK(dialogue_string.at(1).messages.at(1).name == U"Hanako");
	CHECK(dialogue_string.at(1).messages.at(1).messages == U"I like tennis.");

}
