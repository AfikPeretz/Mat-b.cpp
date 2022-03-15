/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <afik peretz>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));

	CHECK(nospaces(mat(5, 3, '@', '-')) == nospaces("@@@@@\n"
													 "@---@\n"
													 "@@@@@"));

	CHECK(nospaces(mat(5, 3, '!', '-')) == nospaces("!!!!!\n"
													 "!---!\n"
													 "!!!!!"));	

	CHECK(nospaces(mat(1, 1, '#', ')')) == nospaces("#"));

	CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n"
													 "$+$\n"
													 "$+$\n"
													 "$+$\n"
													 "$$$"));
	
				
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(122, 5, '^', '%'));
	CHECK_THROWS(mat(10, 4, '$', '%'));
	CHECK_THROWS(mat(12, 3, '@', '-'));
	CHECK_THROWS(mat(11, 6, '%', '='));
	CHECK_THROWS(mat(21, 12, '#', '&'));
	CHECK_THROWS(mat(4, 1, '$', '%'));
	CHECK_THROWS(mat(33, 2, '!', '%'));
	CHECK_THROWS(mat(7, 6, '$', '*'));
	CHECK_THROWS(mat(14, 9, '$', '%'));
	CHECK_THROWS(mat(120, 11, '$', '%'));
    CHECK_THROWS(mat(17, 6, '^', '%'));
	CHECK_THROWS(mat(33, 34, '$', '%'));
	CHECK_THROWS(mat(26, 3, '@', '-'));
	CHECK_THROWS(mat(27, 6, '%', '='));
	CHECK_THROWS(mat(21, 14, '#', '&'));
	CHECK_THROWS(mat(6, 1, '$', '%'));
	CHECK_THROWS(mat(37, 2, '!', '%'));
	CHECK_THROWS(mat(7, 42, '$', '*'));
	CHECK_THROWS(mat(14, 1, '$', '%'));
}



