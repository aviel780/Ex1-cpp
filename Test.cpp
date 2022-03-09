#include "doctest.h"
#include "mat.hpp"


#include <string>
#include <algorithm>
using namespace ariel;
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

TEST_CASE ("Bad input - negitiv number") {
                                    
    CHECK_THROWS(mat(1, -2, '#', '%'));// negitiv number in the row 
    CHECK_THROWS(mat(-2, 1, '#', '%'));// negitiv number in the col 
    CHECK_THROWS(mat(-2, -2, '#', '%'));// negitiv number in the col and in the row
}

TEST_CASE ("Bad input - odd num") {
          
    CHECK_THROWS(mat(6, 3, '#', '%')); // odd num in the col
    CHECK_THROWS(mat(1, 4, '#', '%'));// odd in the row
    CHECK_THROWS(mat(6, 6, '#', '%'));// odd in the col and in the row
}

TEST_CASE ("Bad input - 0") {
                                    
    CHECK_THROWS(mat(0, 7, '#', '%'));// 0 in the col
    CHECK_THROWS(mat(9, 0, '#', '%'));// 0 in the row
    CHECK_THROWS(mat(0, 0, '#', '%'));// 0 in the col and in the row
}


TEST_CASE ("Good input") {
    CHECK(nospaces(mat(9, 7, '@', '-')) ==nospaces("@@@@@@@@@\n"
                                                   "@-------@\n"
                                                   "@-@@@@@-@\n"
                                                   "@-@---@-@\n"
                                                   "@-@@@@@-@\n"
                                                   "@-------@\n"
                                                   "@@@@@@@@@"));
    /* Add more test here */
    CHECK(nospaces(mat(9, 7, '&', '-')) == nospaces("&&&&&&&&&\n"
                                                    "&-------&\n"
                                                    "&-&&&&&-&\n"
                                                    "&-&---&-&\n"
                                                    "&-&&&&&-&\n"
                                                    "&-------&\n"
                                                    "&&&&&&&&&"));

    
    CHECK(nospaces(mat(0, 0, '&', '-')) == nospaces(""));
    
    CHECK(nospaces(mat(11, 7, '<', '>')) == nospaces("<<<<<<<<<<<\n"
                                                     "<>>>>>>>>><\n"
                                                     "<><<<<<<<><\n"
                                                     "<><>>>>><><\n"
                                                     "<><<<<<<<><\n"
                                                     "<>>>>>>>>><\n"
                                                     "<<<<<<<<<<<"));

    CHECK(nospaces(mat(3, 7, '#', '+')) == nospaces("###\n"
                                                    "#+#\n"
                                                    "#+#\n"
                                                    "#+#\n"
                                                    "#+#\n"
                                                    "#+#\n"
                                                    "###"));

    CHECK(nospaces(mat(1, 1, '>', '$')) == nospaces(">"));

    CHECK(nospaces(mat(1, 21, '>', '$')) == nospaces(">\n"
                                                     ">\n"
                                                     ">\n"
                                                     ">\n"
                                                     ">\n"
                                                     ">\n"
                                                     ">\n"
                                                     ">\n"
                                                     ">\n"
                                                     ">\n"
                                                     ">\n"
                                                     ">\n"
                                                     ">\n"
                                                     ">\n"
                                                     ">\n"
                                                     ">\n"
                                                     ">\n"
                                                     ">\n"
                                                     ">\n"
                                                     ">\n"
                                                     ">"));

    CHECK(nospaces(mat(5, 5, '#', '$')) == nospaces("#####\n"
                                                    "#$$$#\n"
                                                    "#$#$#\n"
                                                    "#$$$#\n"
                                                    "#####"));

    CHECK(nospaces(mat(11, 11, '#', '$')) == nospaces("###########\n"
                                                      "#$$$$$$$$$#\n"
                                                      "#$#######$#\n"
                                                      "#$#$$$$$#$#\n"
                                                      "#$#$###$#$#\n"
                                                      "#$#$#$#$#$#\n"
                                                      "#$#$###$#$#\n"
                                                      "#$#$$$$$#$#\n"
                                                      "#$#######$#\n"
                                                      "#$$$$$$$$$#\n"
                                                      "###########"));

    CHECK(nospaces(mat(7, 7, '#', '#')) == nospaces(  "#######\n"
                                                      "#######\n"
                                                      "#######\n"
                                                      "#######\n"
                                                      "#######\n"
                                                      "#######\n"
                                                      "#######"));

    CHECK(nospaces(mat(7, 21, '#', '$')) == nospaces("#######\n"
                                                     "#$$$$$#\n"
                                                     "#$###$#\n"
                                                     "#$#$#$#\n"
                                                     "#$#$#$#\n"
                                                     "#$#$#$#\n"
                                                     "#$#$#$#\n"
                                                     "#$#$#$#\n"
                                                     "#$#$#$#\n"
                                                     "#$#$#$#\n"
                                                     "#$#$#$#\n"
                                                     "#$#$#$#\n"
                                                     "#$#$#$#\n"
                                                     "#$#$#$#\n"
                                                     "#$#$#$#\n"
                                                     "#$#$#$#\n"
                                                     "#$#$#$#\n"
                                                     "#$#$#$#\n"
                                                     "#$###$#\n"
                                                     "#$$$$$#\n"
                                                     "#######"));

    CHECK(nospaces(mat(3, 13, '#', '$')) == nospaces("###\n"
                                                     "#$#\n"
                                                     "#$#\n"
                                                     "#$#\n"
                                                     "#$#\n"
                                                     "#$#\n"
                                                     "#$#\n"
                                                     "#$#\n"
                                                     "#$#\n"
                                                     "#$#\n"
                                                     "#$#\n"
                                                     "#$#\n"
                                                     "###"));

    CHECK(nospaces(mat(3, 7, '#', '$')) == nospaces("###\n"
                                                    "#$#\n"
                                                    "#$#\n"
                                                    "#$#\n"
                                                    "#$#\n"
                                                    "#$#\n"
                                                    "###"));

    CHECK(nospaces(mat(3, 3, '#', '$')) == nospaces("###\n"
                                                    "#$#\n"
                                                    "###\n"));

}