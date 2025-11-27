#include "InvertebrateChecker.h"

InvertebrateChecker::InvertebrateChecker() {
    rules["balmain bug"] = {10,20,20};
    rules["beach worm"] = {9999,20,20};
    rules["crab (solider)"] = {9999,100,100};
    rules["saltwater nippers"] = {9999,100,100};
    rules["sea urchin"] = {9999,10,10};
    rules["squid & cuttlefish"] = {9999,20,20};
}