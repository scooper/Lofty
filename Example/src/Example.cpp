#include "Example.h"

ExampleApp::ExampleApp()
{

}

ExampleApp::~ExampleApp()
{

}

Lofty::App* Lofty::AppInit()
{
    return new ExampleApp();
}