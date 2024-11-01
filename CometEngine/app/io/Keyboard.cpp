#include "Keyboard.h"

Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
{
}

int Keyboard::get_key(int key) const noexcept
{
    return keys[key];
}


void Keyboard::set_key(int key, int action) noexcept
{
    keys[key] = action;
}

