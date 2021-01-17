#include "App.h"
#include "Logger.h"

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