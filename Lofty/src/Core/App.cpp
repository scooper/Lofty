#include "App.h"
#include "Logger.h"
#include "Window.h"
#include "AppEvents.h"
#include "InputEvents.h"

#include <functional>

// TEMP: 
// temp to at least have a render loop
#include <glad/glad.h>

extern Lofty::App* AppInit();

namespace Lofty
{ 
    App::App()
    {
        // bind events
        EventDispatcher::GetInstance().Subscribe(AppCloseEvent::eventType, std::bind(&App::Close, this, std::placeholders::_1));
        EventDispatcher::GetInstance().Subscribe(AppResizeEvent::eventType, std::bind(&App::OnResize, this, std::placeholders::_1));
        EventDispatcher::GetInstance().Subscribe(KeyPressEvent::eventType, std::bind(&App::OnKeyEvent, this, std::placeholders::_1));
        EventDispatcher::GetInstance().Subscribe(KeyReleaseEvent::eventType, std::bind(&App::OnKeyEvent, this, std::placeholders::_1));
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

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

            window->OnUpdate();
        }
    }

    void App::Close(const Event& event)
    {
        LOG_INFO(event.ToString());
        m_Running = false;
    }

    // TEMP?
    void App::OnResize(const Event& event)
    {
        LOG_INFO(event.ToString());
    }

    // TEMP?
    void App::OnKeyEvent(const Event& event)
    {
        LOG_INFO(event.ToString());
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