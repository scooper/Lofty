#pragma once

namespace Lofty
{
    class App
    {
    public:
        App();
        virtual ~App();
        void Run();
    };

    App* AppInit();
}