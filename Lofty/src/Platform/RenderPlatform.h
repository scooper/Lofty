#pragma once


namespace Lofty
{

    enum class RenderAPI
    {
        None,
        OpenGL,
        Vulkan,
        DirectX
    };

    class RenderPlatform
    {
    public:
        static const RenderAPI GetRenderingAPI()
        {
#ifdef USE_OPENGL
            return RenderAPI::OpenGL;
#else
            return RenderAPI::None;
#endif
        }
    };

}