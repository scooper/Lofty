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
    private:
        bool m_Running = true;
    };

    App* AppInit();
}