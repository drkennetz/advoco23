// Day01.cpp
#include <fstream>
#include <iostream>
#include <cctype>

#include "day01.h"

namespace aoc
{

int Day01::parseInputFile()
{
    std::ifstream file(inputFile_);
    if (!file.is_open())
    {
        std::cerr << "Error opening input file: " << inputFile_ << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(file, line))
    {
        parsedLines_.push_back(line);
    }
    return 0;
}

int Day01::solvePartOne()
{
    int total = 0;

    for (std::string string : parsedLines_)
    {
        // Init nulls.
        char firstDigit = '\0';
        char lastDigit = '\0';
        for (char c : string) {
            if (std::isdigit(c))
            {
                if (firstDigit == '\0')
                {
                    firstDigit = c;
                }
                // Inefficient but blegh.
                lastDigit = c;
            }
        }
        int firstDigitInt = (firstDigit != '\0') ? (firstDigit - '0') : 0;
        int lastDigitInt = (lastDigit != '\0') ? (lastDigit - '0') : 0;
        if (firstDigitInt == 0) total += lastDigitInt;
        total += (firstDigitInt * 10) + lastDigitInt;
    }
    return total;
}

}  // namespace aoc
