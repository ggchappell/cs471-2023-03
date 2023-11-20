// pps.hpp
// Glenn G. Chappell
// 2023-10-02
// Header for function prettyPrintSquare

#ifndef FILE_PPS_HPP_INCLUDED
#define FILE_PPS_HPP_INCLUDED

#include <iostream>
// For std::cout
// For std::ostream
#include <string>
// For std::string
// For std::to_string
#include <cstddef>
// For std::size_t

class Compute {
public:
    virtual ~Compute() {}

    virtual int operator()(int n) const = 0;
};


class Square : public Compute {
public:
    virtual ~Square() {}

    virtual int operator()(int n) const
    {
        return n*n;
    }
};


class Triple : public Compute {
public:
    virtual ~Triple() {}

    virtual int operator()(int n) const
    {
        return 3*n;
    }
};


class Format {
public:
    virtual ~Format() {}

    virtual std::string operator()(const std::string & s) const = 0;
};


class Box : public Format {
public:
    virtual ~Box() {}

    virtual std::string operator()(const std::string & s) const
    {
        auto len = s.size() + 4;

        std::string result;
        result += std::string(len, '*') + "\n";
        result += "* " + s + " *\n";
        result += std::string(len, '*') + "\n";
        return result;
    }
};


class ThreePound : public Format {
public:
    virtual ~ThreePound() {}

    virtual std::string operator()(const std::string & s) const
    {
        std::string result = "### " + s + " ###\n";
        return result;
    }
};


inline
void prettyPrintSquare(int n,
                       std::ostream & out = std::cout,
                       const Compute & comp = Square(),
                       const Format & form = Box())
{
    int nn = comp(n);
    std::string nnstr = std::to_string(nn);
    std::string final = form(nnstr);
    out << final;
}

#endif  //#ifndef FILE_PPS_HPP_INCLUDED

