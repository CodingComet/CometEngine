#pragma once
#include <memory>
#include <CometEngine/graphics/GL/Texture.h>
#include <GLM/glm.hpp>
#include "../core/Transform.h"

class Sprite
{
public:
    Sprite() = default;
private:
    std::shared_ptr<Texture> texture;
    glm::vec2 size;
    glm::vec2 tex_coords;
};

template<typename T> // should make concept
void sprite_system(T& state, Sprite& sprite, Transform& transform)
{
    state.get_
}