#include "Window.h"
#include "Core/Logger.h"
#include "Platform/Windows/WindowsWindow.h"

namespace Lofty
{
    Window::Window(const WindowData& data) : m_Data(data)
    {
    }

    Window::~Window()
    {

    }

    std::unique_ptr<Window> Window::Create(const WindowData& data)
    {
        // platform dependent code
#if WINDOWS
        return std::make_unique<WindowsWindow>(data);
#else
        // figure out a way to crash or something if this reaches the else (platform not supported)
        LOG_ERROR("Error: platform not supported!");
#error Platform not supported!
#endif
    }
}