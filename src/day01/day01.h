//------------------------------------------------------------------------------
/// @brief  Day01 puzzle class
#include <string>

namespace aoc
{

class Day01
{

public:
    Day01(std::string inputFile)
        : inputFile_(inputFile)
    {
    }

    void printInputFile();

private:
    std::string inputFile_;
};

}  // aoc

