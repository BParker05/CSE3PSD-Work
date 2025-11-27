#pragma once

#include "Creature.h"

class VertebrateCreature : public Creature {
public:
    VertebrateCreature();
    VertebrateCreature(std::string& species, float length, bool hasEggs);
};
