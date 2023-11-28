// clang++ lib.cpp -std=c++20
#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include "../Utility/OneLineTextReader.h"


// [test_0.txt]
// Apple
//
// Banana
//
// Blueberry


TEST_CASE("testing the add function")
{
	OneLineTextReader reader(U"texts/test/test_0.txt");
	auto result = reader.readOneLineAll();

	CHECK(result.size() == 3);
	CHECK(result.at(0) == U"Apple");
	CHECK(result.at(1) == U"Banana");
	CHECK(result.at(2) == U"Blueberry");

}

