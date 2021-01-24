#include <memory>

#include "RenderContext.h"
#include "Platform/RenderPlatform.h"
#include "Platform/OpenGL/GLContext.h"

namespace Lofty
{
    std::unique_ptr<RenderContext> RenderContext::Create(void* window)
    {
        RenderAPI api = RenderPlatform::GetRenderingAPI();

        switch(api)
        {
        case RenderAPI::None:
            return nullptr;
        case RenderAPI::OpenGL:
            return std::make_unique<GLContext>(static_cast<GLFWwindow*>(window));
        }
    }
}
