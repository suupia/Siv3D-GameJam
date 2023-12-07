#pragma once
#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include "../MessageBox/MultipleDialogueReader.h"


TEST_CASE("MultipleDialogue should return words with line breaks separated by")
{
	auto multiple_dialogue_reader = SingleDialogueReader(U"texts/test/sc_test_0.txt");
	// auto multiple_dialogue_reader = MultipleDialogueReader(U"texts/test/MultipleDialogueReaderTest_0.txt");
	const auto dialogue_string = multiple_dialogue_reader.readMessageAll();
	const auto message_structs = dialogue_string.messages;


	CHECK(message_structs.size() == 3);

	CHECK(message_structs.at(0).name == U"Taro");
	CHECK(message_structs.at(0).messages == U"Hello! I'm Taro.");

	CHECK(message_structs.at(1).name == U"Hanako");
	CHECK(message_structs.at(1).messages == U"Hi!\nI'm Hanako.");

	CHECK(message_structs.at(2).name == U"Taro");
	CHECK(message_structs.at(2).messages == U"Nice to meet you.");

}
