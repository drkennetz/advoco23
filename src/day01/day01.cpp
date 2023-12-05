// Day01.cpp
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <numeric>
#include <regex>


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
        // I want to lowercase for practice and safety :D
        std::string dest;
        dest.resize(line.size());

        // Lowercase the string.
        std::transform(line.begin(),
                       line.end(),
                       dest.begin(),
                       ::tolower);
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
        // if (firstDigitInt == 0) total += lastDigitInt;
        total += (firstDigitInt * 10) + lastDigitInt;
    }
    return total;
}

int Day01::solvePartTwo()
{
    const std::vector<std::string> numbers = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    const std::regex numberOrWord(
        "([1-9]|one|two|three|four|five|six|seven|eight|nine)", std::regex_constants::ECMAScript);
    std::vector<int> answers;
    for (const std::string line : parsedLines_) {
        // print_line(line);

        std::string number_parts;
        std::smatch matches;
        std::string search(line);
        while (std::regex_search(search, matches, numberOrWord)) {
            auto match = matches[1].str();
            auto number_string_index = std::find(numbers.begin(), numbers.end(), match);
            std::string prefix;
            if (number_string_index != numbers.end()) {
                prefix = match.substr(1, match.length() - 1);
                match = std::to_string(number_string_index - numbers.begin() + 1);
            }

            if (number_parts.empty() || number_parts.size() == 1) {
                number_parts += match;
            } else {
                number_parts.at(1) = match.at(0);
            }
            search = prefix + "" + matches.suffix().str();
        }

        if (number_parts.length() == 1) {
            number_parts += number_parts;
        }

        answers.push_back(std::stoi(number_parts));
    }

    return std::accumulate(answers.begin(), answers.end(), 0);
}

}  // namespace aoc
