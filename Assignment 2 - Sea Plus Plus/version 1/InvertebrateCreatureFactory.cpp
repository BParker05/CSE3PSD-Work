#include "InvertebrateCreatureFactory.h"

InvertebrateCreatureFactory::InvertebrateCreatureFactory() {
  // Implementation if needed
}

InvertebrateCreature InvertebrateCreatureFactory::makeCreature(std::string species, float length, bool eggs) {
  return InvertebrateCreature(species, length, eggs);
}

