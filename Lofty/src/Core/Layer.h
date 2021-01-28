#pragma once

#include <string>
#include "Timing.h"

namespace Lofty
{
    class Layer
    {
    public:
        Layer(std::string name) : m_Name(name) {}
        virtual ~Layer() = default;

        virtual void OnActivate() {}
        virtual void OnDeactivate() {}

        virtual void OnUpdate(Duration deltaTime) {}

    protected:
        std::string m_Name;

    };
}
