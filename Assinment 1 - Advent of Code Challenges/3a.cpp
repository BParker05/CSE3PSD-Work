#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

int main() {
    int sum = 0;
    std::ifstream inputFile;
    std::string currentLine;
    std::regex pattern(R"(mul\((\d+),(\d+)\))");
    inputFile.open("C:/Users/Brayden/CLionProjects/CSEPSD Assignment 1/day3_real.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open file\n";
        return 1;  // Exit program with an error code
    }

    while (std::getline(inputFile, currentLine)) {
        std::sregex_iterator it(currentLine.begin(), currentLine.end(), pattern);
        auto end = std::sregex_iterator();

        for (std::sregex_iterator i = it; i != end; ++i) {
            int num1 = std::stoi((*it)[1].str());
            int num2 = std::stoi((*it)[2].str());
            sum += num1 * num2;
            ++it;
        }
    }
    inputFile.close();

    std::cout << "Result of the multiplications: "<< sum;

    return 0;
}