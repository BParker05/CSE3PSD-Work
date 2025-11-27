#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

int main() {
    std::ifstream inputFile;
    std::string currentLine;
    std::vector<int> vector1;
    std::vector<int> vector2;
    int total = 0;
    inputFile.open("C:/Users/Brayden/CLionProjects/CSEPSD Assignment 1/day1_real.txt");
    if (inputFile.is_open()) {
        while (std::getline(inputFile, currentLine)) {
            std::istringstream iss(currentLine);
            int first, second;
            iss >> first >> second;
            vector1.push_back(first);
            vector2.push_back(second);
        }
        std::sort(vector1.begin(), vector1.end());
        std::sort(vector2.begin(), vector2.end());

        for (int i = 0; i < vector1.size(); i++) {
            total += std::abs(vector1[i] - vector2[i]);
        }
        std::cout << "Total distance between lists: " << total;
    }
    return 0;
}
