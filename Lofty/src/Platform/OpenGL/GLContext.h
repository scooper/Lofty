#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Rendering/RenderContext.h"

namespace Lofty
{
    class GLContext : public RenderContext
    {
    public:
        GLContext(GLFWwindow* window);
        void Init() override;
    private:
        GLFWwindow* m_Window;
    };
}