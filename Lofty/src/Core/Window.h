#pragma once
#include <memory>
#include <string>

namespace Lofty
{
    struct WindowData
    {
        WindowData() : width(800), height(600), title("Lofty") {}
        int width;
        int height;
        std::string title;
    };

    class Window
    {
    public:
        Window(const WindowData& data);
        virtual ~Window();
        virtual void Init() = 0;
        virtual void Close() = 0;

        virtual void SwapBuffers() = 0;

        int GetWidth() { return m_Data.width; }
        int GetHeight() { return m_Data.height; }
        // this may be redundant (we only really need the title on initialisation)
        std::string GetTitle() { return m_Data.title; }

        // create the window context - with default values if none specified
        static std::unique_ptr<Window> Create(const WindowData& data = WindowData());

    protected:
        WindowData m_Data;
    };
}