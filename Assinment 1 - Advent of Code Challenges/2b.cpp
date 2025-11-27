#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

bool check (std::vector<int> input) {
    if (not is_sorted(input.begin(), input.end())) {
        if (not std::is_sorted(input.begin(), input.end(), std::greater<int>())) {
            return false;
        }
    }


    for (int i = 0; i < input.size()-1; i++) {
        if (std::abs(input[i] - input[i+1]) > 3 || std::abs(input[i] - input[i+1]) == 0) {
            return false;
        }
    }
    return true;
}

bool checkAgain(std::vector<int> checkAgainInput) {
    for (int i = 0; i < checkAgainInput.size(); i++) {
        std::vector<int> temp = checkAgainInput;
        temp.erase(std::find(temp.begin(), temp.end(), temp[i]));
        if (check(temp)) {
            return true;
        }
    }
    checkAgainInput.pop_back();
    return check(checkAgainInput);

}

bool isSafeReport(std::vector <int> isSafeReportInput) {
    if (check(isSafeReportInput)) {
        return true;
    } else return checkAgain(isSafeReportInput);
}

int main() {
    int safeReports = 0;
    std::ifstream inputFile;
    inputFile.open("C:/Users/Brayden/CLionProjects/CSEPSD Assignment 1/day2_real.txt");

    if (inputFile.is_open()) {

        std::string currentLine;

        while (std::getline(inputFile, currentLine)) {
            std::vector<int> currentInts;
            std::istringstream iss(currentLine);
            int num;

            while (iss >> num) {
                currentInts.push_back(num);
            }
            if (isSafeReport(currentInts)) {
                safeReports++;
            }
            currentInts.clear();
        }
    }
    std::cout << "Number of safe reports: " << safeReports;
    return 0;
}