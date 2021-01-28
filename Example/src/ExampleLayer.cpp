#include "ExampleLayer.h"

// TEMP while we have no renderer functionality
#include <glad/glad.h>

void ExampleLayer::OnUpdate(Lofty::Duration deltaTime)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.5f, 0.5f, 0.7f, 1.0f);

    LOG_INFO("{0}", deltaTime.FloatMilliseconds());
}
