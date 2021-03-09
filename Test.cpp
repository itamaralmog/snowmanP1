#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
#include <iostream>
#include <stdexcept>
using namespace std;

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("good snowman"){
    CHECK(nospaces(ariel::snowman(11114411))==nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(ariel::snowman(23424423))==nospaces("___\n.....\n(-_o)\n(] [)\n(___)"));
    CHECK(nospaces(ariel::snowman(33232124))==nospaces("_\n/_\\\n\\(o_O)\n(] [)>\n(   )"));
    CHECK(nospaces(ariel::snowman(44344444))==nospaces("___\n(_*_)\n(O -)\n(   )\n(   )"));
    CHECK(nospaces(ariel::snowman(12312341+32032103))==nospaces("___\n(_*_)\n(O -)\n(   )\n(   )"));
    CHECK(nospaces(ariel::snowman(12341234))==nospaces("_===_\n(O.-)/\n<(> <)\n(   )"));
    CHECK(nospaces(ariel::snowman(23412341))==nospaces("___\n.....\n\\(-_.)\n(   )\\\n( : )"));
    CHECK(nospaces(ariel::snowman(34123412))==nospaces("_\n/_\\\n(. o)\n/( : )\n(\" \")"));
    CHECK(nospaces(ariel::snowman(41234123))==nospaces("___\n(_*_)\n(o,O)\n(] [)>\n(___)"));
}   
TEST_CASE("good snowman with spaces"){
    CHECK(ariel::snowman(11113111)==" _===_\n (.,.)\n/( : )>\n ( : )");
    CHECK(ariel::snowman(11112113)==" _===_\n\\(.,.)\n ( : )>\n (___)");
    CHECK(ariel::snowman(12312231)==" _===_\n\\(O..)/\n (> <)\n ( : )");
}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(ariel::snowman(555));
    CHECK_THROWS(ariel::snowman(-12341234));
    CHECK_THROWS(ariel::snowman(44444445));
    CHECK_THROWS(ariel::snowman(11111110));
    CHECK_THROWS(ariel::snowman(02344123));
    CHECK_THROWS(ariel::snowman(11212222+1321221));
    CHECK_THROWS(ariel::snowman(123412341));
    CHECK_THROWS(ariel::snowman(1234123));
    CHECK_THROWS(ariel::snowman(012341234));
}

