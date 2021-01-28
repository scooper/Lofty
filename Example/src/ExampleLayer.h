#pragma once

#include <Lofty.h>

class ExampleLayer : public Lofty::Layer
{
public:
    ExampleLayer(std::string name) : Layer(name) {}
    ~ExampleLayer() = default;

    void OnUpdate(Lofty::Duration deltaTime) override;
};