#pragma once

#include "VertebrateChecker.h"
#include "InvertebrateChecker.h"
#include "CreatureFactory.h"
#include <iostream>
#include "VertebrateCreature.h"
#include "InvertebrateCreature.h"
#include "VertebrateCreatureFactory.h"
#include "InvertebrateCreatureFactory.h"

class SeaPlusPlusEngine {
public:
    VertebrateChecker* vertebrateChecker;
    InvertebrateChecker* invertebrateChecker;
    VertebrateCreatureFactory* vertebrateCreatureFactory;
    InvertebrateCreatureFactory* invertebrateCreatureFactory;

    SeaPlusPlusEngine();

    std::string checkVertebrate();
    std::string checkInvertebrate();

    VertebrateCreature MakeVertebrateCreature(VertebrateCreatureFactory* creatureFactory, std::string species);
    InvertebrateCreature MakeInvertebrateCreature(InvertebrateCreatureFactory* creatureFactory, std::string species);

};
