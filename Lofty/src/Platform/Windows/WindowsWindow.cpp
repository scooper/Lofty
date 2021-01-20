#include "WindowsWindow.h"

namespace Lofty
{

    static void GLFWErrorCallback(int errorCode, const char* message)
    {
        LOG_ERROR("GLFW Error {0}: {1}", errorCode, message);
    }

    WindowsWindow::WindowsWindow(const WindowData& data) : Window(data)
    {
        Init();
    }

    WindowsWindow::~WindowsWindow()
    {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    void WindowsWindow::Init()
    {
        LOG_INFO("Initialising GLFW");

        glfwSetErrorCallback(GLFWErrorCallback);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef _DEBUG
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif
        m_Window = glfwCreateWindow(m_Data.width, m_Data.height, m_Data.title.c_str(), NULL, NULL);

        if (!m_Window)
        {
            glfwTerminate();
            LOG_ERROR("GLFW Failed to initialise!");
            // need some other event to make the program shut down (turn App's m_Running field to false)
        }

        glfwMakeContextCurrent(m_Window);
        glfwSwapInterval(1);
    }
}