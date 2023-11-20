// pps_test.cpp
// Glenn G. Chappell
// 2023-10-04
//
// For CS 471 Fall 2023
// Test suite for class Squarer
// Uses doctest unit-testing framework
// Requires doctest.h, pps.hpp

// Includes for code to be tested
#include "pps.hpp"       // For prettyPrintSquare
#include "pps.hpp"       // Double-inclusion check, for testing only

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
                             // doctest writes main for us
#include "doctest.h"         // For doctest

#include <sstream>
using std::ostringstream;
#include <string>
using std::string;


class ComputeMock : public Compute {
public:
    virtual ~ComputeMock() {}

    virtual int operator()(int n) const
    {
        return n;
    }
};


class FormatMock : public Format {
public:
    virtual ~FormatMock() {}

    virtual std::string operator()(const std::string & s) const
    {
        return s;
    }
};


TEST_CASE( "prettyPrintSquare gives correct results" )
{
    ostringstream oss;

    int param = -11;
    string expected = "*******\n* 121 *\n*******\n";
    prettyPrintSquare(param, oss);
    CHECK(oss.str() == expected);
}


TEST_CASE( "prettyPrintSquare works with Triple object" )
{
    ostringstream oss;
    int param = 8;
    string expected = "24";
    prettyPrintSquare(param, oss, Triple(), FormatMock());
    CHECK(oss.str() == expected);
}


TEST_CASE( "prettyPrintSquare works with ThreePound object" )
{
    ostringstream oss;
    int param = 8;
    string expected = "### 8 ###\n";
    prettyPrintSquare(param, oss, ComputeMock(), ThreePound());
    CHECK(oss.str() == expected);
}


TEST_CASE( "Square gives correct results" )
{
    Square square;

    {
    int param = 3;
    int expected = 9;
    CHECK(square(param) == expected);
    }

    {
    int param = -2;
    int expected = 4;
    CHECK(square(param) == expected);
    }
}


TEST_CASE( "Box gives correct results" )
{
    Box box;

    {
    string param = "abc";
    string expected = "*******\n* abc *\n*******\n";
    CHECK(box(param) == expected);
    }
}

