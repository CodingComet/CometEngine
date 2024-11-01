#include "Renderer.h"
#include <iostream>

Renderer::Renderer(GLADloadproc load)
{
    if (!gladLoadGLLoader(load))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
}

void Renderer::set_clear_color(const glm::vec3 &color)
{
    glClearColor(color.r, color.g, color.b, 1.f);
}

void Renderer::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}
