#include <iostream>
#include <fstream>
#include <vector>

bool check(std::vector<std::vector<char>> input, int i, int j) {

    if (input[i+1][j+1] == 'M' && input[i-1][j-1] == 'S') {
        if (input[i+1][j-1] == 'M' && input[i-1][j+1] == 'S') {
            return true;
        }
        if (input[i+1][j-1] == 'S' && input[i-1][j+1] == 'M') {
            return true;
        }
    }

    if (input[i+1][j+1] == 'S' && input[i-1][j-1] == 'M') {
        if (input[i+1][j-1] == 'M' && input[i-1][j+1] == 'S') {
            return true;
        }
        if (input[i+1][j-1] == 'S' && input[i-1][j+1] == 'M') {
            return true;
        }
    }
    return false;

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


    for (int i = 1; i < charMatrix.size()-1; i++) {
        for (int j = 1; j < charMatrix[i].size()-1; j++) {
            if (charMatrix[i][j] == 'A') {
                if (check(charMatrix, i, j)) {
                    numOfMatches++;
                }
            }
        }
    }

    std::cout << "Number of times an \"X-MAS\" appears: " << numOfMatches;

    return 0;
}
