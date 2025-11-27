#include "VertebrateChecker.h"

VertebrateChecker::VertebrateChecker() {
    rules["australian salmon"] = {9999,5,20};
    rules["blue drummer"] = {9999,0,0};
    rules["bonito"] = {9999,10,20};
    rules["cobia"] = {9999,5,20};
    rules["flounder"] = {25,20,20};
    rules["luderick"] = {27,10,20};
    rules["morwong grey (rubberlip)"] = {30,10,20};
    rules["morwong (jackass)"] = {30,10,20};
    rules["morwong (red)"] = {30,5,20};
}