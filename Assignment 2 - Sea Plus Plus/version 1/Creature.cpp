#include "Creature.h"

Creature::Creature() : species(""), length(0.0f), hasEggs(false) {}

Creature::Creature(std::string& species, float length, bool hasEggs)
    : species(species), length(length), hasEggs(hasEggs) {}

std::string Creature::getSpecies() const {
  return species;
}

float Creature::getLength() const {
  return length;
}

bool Creature::getEggs() const {
  return hasEggs;
}
