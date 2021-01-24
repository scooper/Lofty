#pragma once
#include <memory>

namespace Lofty
{
    class RenderContext
    {
    public:
        virtual ~RenderContext() = default;

        virtual void Init() = 0;

        static std::unique_ptr<RenderContext> Create(void* window);
    };
}
