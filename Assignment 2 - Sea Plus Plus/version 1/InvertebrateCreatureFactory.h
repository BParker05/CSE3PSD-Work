#pragma once

#include "CreatureFactory.h"
#include "InvertebrateCreature.h"

class InvertebrateCreatureFactory : public CreatureFactory {
public:
    InvertebrateCreatureFactory();

    InvertebrateCreature makeCreature(std::string species, float length, bool eggs);
};
