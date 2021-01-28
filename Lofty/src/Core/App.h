#pragma once
#include "Timing.h"
#include "Layers.h"
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
        void OnResize(const Event& event);

        // TEMP? just to test events
        void OnEvent(const Event& event);

        void OnMinimiseRestore(const Event& event);

    protected:
        Layers m_Layers;

    private:
        bool m_Running = true;
        bool m_Minimised = false;
        TimePoint m_LastFrame;
    };

    App* AppInit();
}