#include <algorithm>
#include "Layers.h"

namespace Lofty
{
    Layers::~Layers()
    {
        for (Layer* layer : m_Layers)
        {
            delete layer;
        }
    }

    void Layers::Add(Layer* layer)
    {
        m_Layers.push_back(layer);
        layer->OnActivate();
    }

    void Layers::Remove(Layer* layer)
    {
        auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
        if (it >= m_Layers.begin())
        {
            (*it)->OnDeactivate();
            m_Layers.erase(it);
        }
    }
}
