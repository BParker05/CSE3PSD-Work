#pragma once

#include "Creature.h"

class InvertebrateCreature : public Creature {
public:
    InvertebrateCreature();
    InvertebrateCreature(std::string& species, float length, bool hasEggs);
};
