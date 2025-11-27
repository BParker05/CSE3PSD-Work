#include <iostream>
#include <fstream>
#include <vector>

int check(std::vector<std::vector<char>> input, int i, int j) {
    int numOfMatches = 0;
    int widthBound = input.size()-3;
    int heightBound = input[0].size()-3;
    bool right,down,left,up;
    right = down = left = up = false;

    if (i < widthBound) {
        right = true;
        if (input[i+1][j] == 'M' && input[i+2][j] == 'A' && input[i+3][j] == 'S') {
            numOfMatches++;
        }
    }
    if (j < heightBound) {
        down = true;
        if (input[i][j+1] == 'M' && input[i][j+2] == 'A' && input[i][j+3] == 'S') {
            numOfMatches++;
        }
    }
    if (i >= 3) {
        left = true;
        if (input[i-1][j] == 'M' && input[i-2][j] == 'A' && input[i-3][j] == 'S') {
            numOfMatches++;
        }
    }
    if (j >= 3) {
        up = true;
        if (input[i][j-1] == 'M' && input[i][j-2] == 'A' && input[i][j-3] == 'S') {
            numOfMatches++;
        }
    }
    if (right && down) {
        if (input[i+1][j+1] == 'M' && input[i+2][j+2] == 'A' && input[i+3][j+3] == 'S') {
            numOfMatches++;
        }
    }
    if (left && down) {
        if (input[i-1][j+1] == 'M' && input[i-2][j+2] == 'A' && input[i-3][j+3] == 'S') {
            numOfMatches++;
        }

    }
    if (left && up) {
        if (input[i-1][j-1] == 'M' && input[i-2][j-2] == 'A' && input[i-3][j-3] == 'S') {
            numOfMatches++;
        }
    }
    if (right && up) {
        if (input[i+1][j-1] == 'M' && input[i+2][j-2] == 'A' && input[i+3][j-3] == 'S') {
            numOfMatches++;
        }
    }
    return numOfMatches;

}

int main() {
    int numOfMatches = 0;
    std::ifstream file("C:/Users/Brayden/CLionProjects/CSEPSD Assignment 1/day4_real.txt");
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::vector<std::vector<char>> charMatrix;
    std::string line;

    while (std::getline(file, line)) {
        std::vector<char> row(line.begin(), line.end());
        charMatrix.push_back(row);
    }

    file.close();


    for (int i = 0; i < charMatrix.size(); i++) {
        for (int j = 0; j < charMatrix[i].size(); j++) {
            if (charMatrix[i][j] == 'X') {
                numOfMatches += check(charMatrix, i, j);
            }
        }
    }

    std::cout << "Number of times \"XMAS\" appears: " << numOfMatches;

    return 0;
}
