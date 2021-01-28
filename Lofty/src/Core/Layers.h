#pragma once
#include <vector>
#include "Layer.h"

namespace Lofty
{
    class Layers
    {
    public:
        Layers() {}
        ~Layers();

        void Add(Layer* layer);
        void Remove(Layer* layer);

        std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer*>::iterator end() { return m_Layers.end(); }

    private:
        std::vector<Layer*> m_Layers;
    };
}


