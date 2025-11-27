#include "SeaPlusPlusEngine.h"

SeaPlusPlusEngine::SeaPlusPlusEngine() {
    vertebrateChecker = new VertebrateChecker();
    invertebrateChecker = new InvertebrateChecker();
    vertebrateCreatureFactory = new VertebrateCreatureFactory();
    invertebrateCreatureFactory = new InvertebrateCreatureFactory();
}

VertebrateCreature SeaPlusPlusEngine::MakeVertebrateCreature(VertebrateCreatureFactory* creatureFactory, std::string species) {
  float length;
  char eggs;
  std::cout << "How long is your creature? (cm)" << std::endl;
  std::cin >> length;
  std::cout << "Is your creature carrying eggs? (y/n)" << std::endl;
  std::cin >> eggs;

  return creatureFactory->makeCreature(species, length, eggs == 'y');
}

InvertebrateCreature SeaPlusPlusEngine::MakeInvertebrateCreature(InvertebrateCreatureFactory* creatureFactory, std::string species) {
  float length;
  char eggs;
  std::cout << "How long is your creature? (cm)" << std::endl;
  std::cin >> length;
  std::cout << "Is your creature carrying eggs? (y/n)" << std::endl;
  std::cin >> eggs;

  return creatureFactory->makeCreature(species, length, eggs == 'y');
}


std::string SeaPlusPlusEngine::checkVertebrate() {
  std::string output = "";
  std::string species;

  std::map<std::string, std::vector<int>> fishRules = vertebrateChecker->getRules();
  std::cout << "Which type of Vertebrate would you like to check? (enter name exactly)" << std::endl;
  int index = 1;
  for (auto& pair : fishRules) {
    std::cout << index << ". " << pair.first << std::endl;
      ++index;
  }
  std::cin >> species;

  int inBag;
  int inPossession;

  std::cout<< "How many of this species do you have in your bag? " << std::endl;
  std::cin >> inBag;
  std::cout << "How many of this species do you have in your Possession? " << std::endl;
  std::cin >> inPossession;

  VertebrateCreature fish = MakeVertebrateCreature(vertebrateCreatureFactory, species);

  if (fishRules[fish.getSpecies()][0] < fish.getLength()) {
    output = "Your creature is too long, release it";
  } else if (fishRules[fish.getSpecies()][1] >= inBag) {
    output = "You already have too many in your bag, release it";
  } else if (fishRules[fish.getSpecies()][2] >= inPossession) {
    output = "You already have too many in your possession, release it";
  } else {
    output = "it's a keeper!";
  }

  return output;
}

std::string SeaPlusPlusEngine::checkInvertebrate() {
  std::string output = "";
  std::string species;

  std::map<std::string, std::vector<int>> fishRules = invertebrateChecker->getRules();
  std::cout << "Which type of Invertebrate would you like to check? (enter name exactly)" << std::endl;
  int index = 1;
  for (auto& pair : fishRules) {
    std::cout << index << ". " << pair.first << std::endl;
    ++index;
  }
  std::cin >> species;

  int inBag;
  int inPossession;

  std::cout<< "How many of this species do you have in your bag? " << std::endl;
  std::cin >> inBag;
  std::cout << "How many of this species do you have in your Possession? " << std::endl;
  std::cin >> inPossession;

  InvertebrateCreature fish = MakeInvertebrateCreature(invertebrateCreatureFactory, species);

  if (fishRules[fish.getSpecies()][0] < fish.getLength()) {
    output = "Your creature is too long, release it";
  } else if (fishRules[fish.getSpecies()][1] >= inBag) {
    output = "You already have too many in your bag, release it";
  } else if (fishRules[fish.getSpecies()][2] >= inPossession) {
    output = "You already have too many in your possession, release it";
  } else {
    output = "it's a keeper!";
  }

  return output;
}
