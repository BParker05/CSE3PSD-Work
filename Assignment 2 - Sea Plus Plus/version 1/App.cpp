#include "App.h"

App::App() {
  engine = nullptr;
}

App::~App() {
  delete engine;
}

int App::start() {
  engine = new SeaPlusPlusEngine();
  return 0;
}

int App::getInput() {
  int userInput;
  std::cout << "What would you like to do? \n"
            << "1. Check Vertebrate\n"
            << "2. Check Invertebrate\n"
            << "3. Exit\n"
            << "1,2 or 3: ";
  std::cin >> userInput;
  if (userInput == 1 || userInput == 2 || userInput == 3) {
    return userInput;
  } else {
    return 3;
  }
}

int App::run() {
  std::cout << "Welcome to SeaPlusPlus!" << std::endl;
  bool keepRunning = true;

  while (keepRunning) {
    int userInput = getInput();
    switch (userInput) {
      case 1:
        std::cout << engine->checkVertebrate();
      break;
      case 2:
        std::cout << engine->checkInvertebrate();
      break;
      case 3:
        keepRunning = false;
      break;
      default:
        std::cout << "Invalid input. Try again." << std::endl;
      break;
    }
  }
  return 0;
}
