#pragma once

#include <string>

class Creature {
public:
    Creature();
    Creature(std::string& species, float length, bool hasEggs);

    std::string getSpecies() const;
    float getLength() const;
    bool getEggs() const;

protected:
    std::string species;
    float length;
    bool hasEggs;
};
