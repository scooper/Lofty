#pragma once

namespace Lofty
{
    class App
    {
    public:
        App();
        virtual ~App();
        void Run();
    private:
        bool m_Running = true;
    };

    App* AppInit();
}