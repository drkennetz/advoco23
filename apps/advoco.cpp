#include <iostream>
#include <day01.h>

int main() {
    std::string filePath = "/home/dkennetz/advoco23/inputs/day01/input.txt";
    aoc::Day01 day(filePath);
    day.printInputFile();
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
