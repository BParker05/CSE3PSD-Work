#pragma once

#include "CreatureFactory.h"
#include "VertebrateCreature.h"

class VertebrateCreatureFactory : public CreatureFactory {
public:
    VertebrateCreatureFactory();

    VertebrateCreature makeCreature(std::string species, float length, bool eggs);
};
