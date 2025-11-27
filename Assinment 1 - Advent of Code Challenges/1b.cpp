#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::ifstream inputFile;
    std::string currentLine;
    std::vector <int> vector1;
    std::vector <int> vector2;
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

        for (int i = 0; i < vector1.size(); i++) {
            int tally = 0;
            for (int j = 0; j < vector2.size(); j++) {
                if (vector1[i] == vector2[j]) {
                    tally++;
                }
            }
            total += vector1[i] * tally;
        }
    }
    std::cout << "Similarity score: " << total;
    return 0;
}
