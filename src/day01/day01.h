//------------------------------------------------------------------------------
/// @brief  Day01 puzzle class
#include <string>
#include <vector>

namespace aoc
{

class Day01
{

public:
    Day01(){};
    // Don't know if these can be negative
    int parseInputFile();
    int solvePartOne();

private:
    std::string inputFile_ = "./input1.txt";
    std::vector<std::string> parsedLines_;
};

}  // aoc

