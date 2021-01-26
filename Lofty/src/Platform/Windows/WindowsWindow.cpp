#include "WindowsWindow.h"
#include "Rendering/RenderContext.h"
#include "Core/Event.h"
#include "Core/AppEvents.h"
#include "Core/InputEvents.h"

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
        Close();
    }

    void WindowsWindow::Init()
    {
        LOG_INFO("Initialising GLFW");

        if(!glfwInit())
        {
            LOG_ERROR("GLFW Failed to initialise");
        }

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
            LOG_ERROR("GLFW Failed to create window");
            // need some other event to make the program shut down (turn App's m_Running field to false)
        }


        auto context = RenderContext::Create(m_Window);

        glfwSetWindowUserPointer(m_Window, &m_Data);

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
            {
                AppCloseEvent event;
                EventDispatcher::GetInstance().Post(event);
            });

        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
            {
                WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);

                data->height = height;
                data->width = width;

                AppResizeEvent event(width, height);
                EventDispatcher::GetInstance().Post(event);

            });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
            {
                // convert to enum format (GLFW directly translates)
                Key loftyKey = Key{ key };

                if (loftyKey == Key::UNKNOWN)
                    return;

                switch (action)
                {
                case GLFW_RELEASE:
                {
                    KeyReleaseEvent event(loftyKey);
                    EventDispatcher::GetInstance().Post(event);
                    break;
                }
                case GLFW_PRESS:
                case GLFW_REPEAT:
                {
                    KeyPressEvent event(loftyKey);
                    EventDispatcher::GetInstance().Post(event);
                    break;
                }
                default:
                    break;
                }
            });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
            {
                // convert to enum format (GLFW directly translates)
                MouseButton loftyMB = MouseButton{ button };

                switch (action)
                {
                case GLFW_RELEASE:
                {
                    MouseReleaseEvent event(loftyMB);
                    EventDispatcher::GetInstance().Post(event);
                    break;
                }
                case GLFW_PRESS:
                {
                    MousePressEvent event(loftyMB);
                    EventDispatcher::GetInstance().Post(event);
                    break;
                }
                default:
                    break;
                }
            });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
            {
                MouseMoveEvent event(xpos, ypos);
                EventDispatcher::GetInstance().Post(event);
            });

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
            {
                ScrollEvent event(xoffset, yoffset);
                EventDispatcher::GetInstance().Post(event);
            });
        
    }

    void WindowsWindow::Close()
    {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        SwapBuffers();
    }

    void WindowsWindow::SwapBuffers()
    {
        glfwSwapBuffers(m_Window);
    }
}