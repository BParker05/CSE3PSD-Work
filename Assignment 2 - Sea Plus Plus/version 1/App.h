#pragma once

#include "SeaPlusPlusEngine.h"
#include <iostream>

class App {
public:
    SeaPlusPlusEngine* engine;

    App();
    ~App();

    int start();
    int run();
    int getInput();
};
