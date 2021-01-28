#include "Example.h"
#include "ExampleLayer.h"

ExampleApp::ExampleApp()
{
    m_Layers.Add(new ExampleLayer("Example Layer"));
}

ExampleApp::~ExampleApp()
{

}

Lofty::App* Lofty::AppInit()
{
    return new ExampleApp();
}