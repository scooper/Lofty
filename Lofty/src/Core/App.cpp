#include "App.h"
#include "Logger.h"
#include "Window.h"
#include "AppEvents.h"

#include <functional>

// TEMP: 
// temp to at least have a render loop
#include <glad/glad.h>
#include <GLFW/glfw3.h>

extern Lofty::App* AppInit();

namespace Lofty
{ 
    App::App()
    {
        EventDispatcher::GetInstance().Subscribe(AppCloseEvent::eventType, std::bind(&App::Close, this, std::placeholders::_1));
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
            // TEMP: 
            // we need this temporarily so windows doesnt think the program is hanging on an infinite loop
            glfwPollEvents();
            glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

            window->SwapBuffers();
        }
    }

    void App::Close(const Event& event)
    {
        LOG_INFO(event.ToString());
        m_Running = false;
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