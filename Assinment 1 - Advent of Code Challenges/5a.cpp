#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

bool isCorrectOrder(const std::vector<int> &update, const std::unordered_map<int, std::unordered_set<int>> &rules) {
    std::unordered_map<int, int> index_map;
    for (int i = 0; i < update.size(); ++i) {
        index_map[update[i]] = i;
    }

    for (const auto &[first, second_set] : rules) {
        if (index_map.find(first) != index_map.end()) {
            for (int second : second_set) {
                if (index_map.find(second) != index_map.end() && index_map[first] > index_map[second]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int result = 0;
    std::string currentLine;
    std::unordered_map<int, std::unordered_set<int>> rules;
    std::vector<std::vector<int>> updates;

    std::ifstream file("C:/Users/Brayden/CLionProjects/CSEPSD Assignment 1/day5_real.txt");
    if (!file) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    while (getline(file, currentLine)) {
        if (currentLine.empty()) {
            break;
        }
        std::stringstream ss(currentLine);
        int first, second;
        char separator;
        ss >> first >> separator >> second;
        rules[first].insert(second);
    }

    while (getline(file, currentLine)) {
        if (currentLine.empty()) {
            continue;
        }
        std::vector<int> update;
        std::stringstream ss(currentLine);
        int num;
        char separator;
        while (ss >> num) {
            update.push_back(num);
            ss >> separator;
        }
        updates.push_back(update);
    }

    file.close();

    for (const auto update : updates) {
        if (isCorrectOrder(update, rules)) {
            result += update[update.size() / 2];
        }
    }

    std::cout << "Sum of middle numbers: " << result;

    return 0;
}