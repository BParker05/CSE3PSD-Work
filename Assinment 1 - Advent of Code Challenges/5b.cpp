#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

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

std::vector<int> sortUpdate(const std::vector<int> &update, const std::unordered_map<int, std::unordered_set<int>> &rules) {
    std::unordered_map<int, int> dependency_count;
    std::unordered_map<int, std::vector<int>> dependents;

    for (int page : update) {
        dependency_count[page] = 0;
        dependents[page] = {};
    }

    for (const auto &[first, second_set] : rules) {
        if (dependency_count.find(first) != dependency_count.end()) {
            for (int second : second_set) {
                if (dependency_count.find(second) != dependency_count.end()) {
                    dependents[first].push_back(second);
                    dependency_count[second]++;
                }
            }
        }
    }

    std::vector<int> sorted_update;
    std::vector<int> no_dependencies;
    for (const auto &[page, count] : dependency_count) {
        if (count == 0) {
            no_dependencies.push_back(page);
        }
    }

    while (!no_dependencies.empty()) {
        sort(no_dependencies.begin(), no_dependencies.end()); // Ensure stable order
        int page = no_dependencies.front();
        no_dependencies.erase(no_dependencies.begin());
        sorted_update.push_back(page);

        for (int dependent : dependents[page]) {
            if (--dependency_count[dependent] == 0) {
                no_dependencies.push_back(dependent);
            }
        }
    }
    return sorted_update;
}

int main() {
    std::unordered_map<int, std::unordered_set<int>> rules;
    std::string currentLine;
    std::vector<std::vector<int>> updates;
    int result = 0;

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

    for (const auto &update : updates) {
        if (!isCorrectOrder(update, rules)) {
            std::vector<int> corrected = sortUpdate(update, rules);
            result += corrected[corrected.size() / 2]; // Get the middle element
        }
    }
    std::cout << "Sum of middle numbers from updates that were corrected: " << result;

    return 0;
}
