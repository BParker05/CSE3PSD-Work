#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> getRegexMatches(std::string text, std::regex pattern){
    std::vector<std::string> matches;
    std::sregex_iterator begin = std::sregex_iterator(text.begin(), text.end(), pattern);
    std::sregex_iterator end = std::sregex_iterator();

    for(std::sregex_iterator i = begin; i != end; i++){
        matches.push_back((*i).str());
    }
    return matches;
}

int main(){
    int sumOfMuls = 0;
    std::vector<std::string> inputData;
    std::string temp;
    std::regex command_regex("do\\(\\)|don\\'t\\(\\)|mul\\([0-9]{1,3},[0-9]{1,3}\\)");
    std::regex number_in_command_regex("[0-9]{1,3}");
    std::string dataStr;
    bool isDoing = true;

    std::ifstream inFile("C:/Users/Brayden/CLionProjects/CSEPSD Assignment 1/day3_real.txt");
    while (std::getline(inFile,temp)) {
        inputData.push_back(temp);
    }
    for (int i = 0; i < inputData.size(); ++i) {
        dataStr = dataStr.append(inputData[i]);
    }
    inFile.close();

    std::vector<std::string> SplitOnDont = getRegexMatches(dataStr, command_regex);

    for (int i = 0; i < SplitOnDont.size(); ++i) {
        if (isDoing) {
            if (SplitOnDont[i].find("mul") != std::string::npos) {
                std::vector<std::string> tempNumbers = getRegexMatches(SplitOnDont[i],number_in_command_regex);
                int num1 = stoi(tempNumbers.at(0));
                int num2 = stoi(tempNumbers.at(1));
                sumOfMuls += num1 * num2;
            }
            if (SplitOnDont[i].find("don't()") != std::string::npos) {
                isDoing = false;
            }
        }
        if (SplitOnDont[i].find("do()") != std::string::npos) {
            isDoing = true;
        }
    }


    std::cout << "Sum of multiplications: " << sumOfMuls;
}