#include <iostream>

int main() {
    int userInput;
    std::cout << "What would you like to do? \n" << "1.Check Vertebrate\n" << "2.Check Invertebrate\n" << "3.Exit\n" << "Please choose 1,2 or 3 ";
    std::cin >> userInput;
    std::cout << userInput;
    return 0;
}