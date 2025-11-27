#include "VertebrateCreature.h"

VertebrateCreature::VertebrateCreature()
    : Creature() {}

VertebrateCreature::VertebrateCreature(std::string& species, float length, bool hasEggs)
    : Creature(species, length, hasEggs) {}
