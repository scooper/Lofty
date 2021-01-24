#include "GLContext.h"
#include "Core/Logger.h"

namespace Lofty
{
    static void GLErrorMessageCallback(GLenum source,
        GLenum type, GLuint id, GLenum severity, GLsizei length,
        const GLchar* message, const void* userParam)
    {
        // ignore non-significant error/warning codes
        if (id == 131169 || id == 131185 || id == 131218 || id == 131204) return;

        // break on error
        switch (type)
        {
        case GL_DEBUG_TYPE_ERROR:
            LOG_ERROR("OpenGl Debug message ({0}): {1}", id, message);
            break;
        default:
            LOG_INFO("OpenGl Debug message ({0}): {1}", id, message);
        }
    }

    GLContext::GLContext(GLFWwindow* window) : m_Window(window)
    {
        Init();
    }

    void GLContext::Init()
    {
        glfwMakeContextCurrent(m_Window);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if (status == 0)
        {
            LOG_ERROR("Error initialising GLAD");
        }

        LOG_INFO("OpenGL Info: {0}", glGetString(GL_VERSION));

        GLint flags;
        glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
        if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
        {
            // initialize debug output 
            glEnable(GL_DEBUG_OUTPUT);
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
            glDebugMessageCallback(GLErrorMessageCallback, nullptr);
            glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
        }
    }
}


