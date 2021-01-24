#pragma once
#include <memory>
#include <GLFW/glfw3.h>
#include "Core/Window.h"
#include "Core/Logger.h"

namespace Lofty
{
    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowData& data);
        virtual ~WindowsWindow();

        void Init() override;
        void Close() override;

        void SwapBuffers() override;
    private:
        GLFWwindow* m_Window;
    };

}