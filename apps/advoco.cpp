#include <iostream>
#include <day01.h>

int main() {
    aoc::Day01 day;
    const auto rc = day.parseInputFile();
    const auto soln1 = day.solvePartOne();

    std::cout << "Part 1 solution: " << soln1 << std::endl;
    return 0;
}
