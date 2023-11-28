// clang++ lib.cpp -std=c++20
#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

int my_add(int a, int b) { return a + b; }

TEST_CASE("testing the add function") { CHECK(my_add(1, 2) == 3); }

TEST_CASE("will fail") { CHECK(my_add(1, 2) == 3); }
