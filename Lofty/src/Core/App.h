#pragma once
#include "Event.h"

namespace Lofty
{
    class App
    {
    public:
        App();
        virtual ~App();
        void Run();
        void Close(const Event& event);
        // TEMP?
        void OnResize(const Event& event);
        // TEMP?
        void OnKeyEvent(const Event& event);
    private:
        bool m_Running = true;
    };

    App* AppInit();
}