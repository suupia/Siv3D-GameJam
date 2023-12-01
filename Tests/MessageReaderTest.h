#pragma once

#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include "../MessageBox/MessageReader.h"


TEST_CASE("MessageReader should return words with line breaks separated by")
{
	auto message_reader = MessageReader(U"texts/test/sc_test_0.txt");
	const auto message_structs = message_reader.readMessageAll();


	CHECK(message_structs.size() == 4);
	CHECK(message_structs.at(0).name == U"Taro");

}

