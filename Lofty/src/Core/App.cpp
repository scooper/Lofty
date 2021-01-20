#include "App.h"
#include "Logger.h"
#include "Window.h"

extern Lofty::App* AppInit();

namespace Lofty
{ 
    App::App()
    {

    }

    App::~App()
    {
        
    }

    void App::Run()
    {
        LOG_INFO("Application started!");

        auto window = Window::Create();

        while (m_Running)
        {
            // do stuff
        }
    }
}


int main(int argc, char** argv)
{
    Lofty::Logger::Init();

    Lofty::App* app = Lofty::AppInit();
    app->Run();


    // app must be deleted on program end
    delete app;

    return 0;
}