// clang++ lib.cpp -std=c++20
#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include "../MessageBox/OneLineTextReader.h"


// [test_0.txt]
// Apple
//
// Banana
//
// Blueberry


TEST_CASE("readOneLineAll should return words with line breaks separated by")
{
	OneLineTextReader reader(U"texts/test/test_0.txt");
	auto result = reader.readOneLineAll();

	CHECK(result.size() == 3);
	CHECK(result.at(0) == U"Apple");
	CHECK(result.at(1) == U"Banana");
	CHECK(result.at(2) == U"Blueberry");

}

