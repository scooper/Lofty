#pragma once
// these include paths aren't very clear that it's for the engine (needs to include lofty)
#include <Lofty.h>

class ExampleApp : public Lofty::App
{
public:
    ExampleApp();
    ~ExampleApp();
};

Lofty::App* Lofty::AppInit();


