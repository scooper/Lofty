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
        EventDispatcher::GetInstance().Subscribe(AppCloseEvent::eventType, EVENT_BIND_FUNC(App::Close, this));
        EventDispatcher::GetInstance().Subscribe(AppResizeEvent::eventType, EVENT_BIND_FUNC(App::OnResize, this));
        EventDispatcher::GetInstance().Subscribe({ AppMinimiseEvent::eventType, AppRestoreEvent::eventType }, EVENT_BIND_FUNC(App::OnMinimiseRestore, this));

        // TEMP?
        EventDispatcher::GetInstance().Subscribe({ KeyPressEvent::eventType,
                                                   MouseMoveEvent::eventType,
                                                   MousePressEvent::eventType,
                                                   ScrollEvent::eventType }, EVENT_BIND_FUNC(App::OnEvent, this));
    }

    App::~App()
    {

    }

    void App::Run()
    {
        LOG_INFO("Application started!");

        auto window = Window::Create();

        // main loop
        while (m_Running)
        {
            Time time;
            TimePoint now = time.Now();
            Duration deltaTime = now - m_LastFrame;
            m_LastFrame = now;

            for (Layer* layer : m_Layers)
            {
                layer->OnUpdate(deltaTime);
            }

            // window system specific code required after each loop
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
    void App::OnEvent(const Event& event)
    {
        LOG_INFO(event.ToString());
    }

    void App::OnMinimiseRestore(const Event& event)
    {
        if (event.Type() == AppMinimiseEvent::eventType)
            m_Minimised = true;
        
        if (event.Type() == AppRestoreEvent::eventType)
            m_Minimised = false;

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