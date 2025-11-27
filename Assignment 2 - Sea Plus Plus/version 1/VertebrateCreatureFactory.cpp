#include "VertebrateCreatureFactory.h"

VertebrateCreatureFactory::VertebrateCreatureFactory() {
  // Implementation if needed
}

VertebrateCreature VertebrateCreatureFactory::makeCreature(std::string species, float length, bool eggs) {
  return VertebrateCreature(species, length, eggs);
}

