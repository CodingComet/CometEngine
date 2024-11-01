#pragma once
#include "Mouse.h"
#include "Keyboard.h"

class Window;

class Input
{
public:
    Input();
    ~Input();

    void update();

    int get_key(int key) const { return keyboard.get_key(key); };
    int get_button(int button) const { return mouse.get_button(button); };

    friend class Window;
private:
    Keyboard keyboard;
    Mouse mouse;
};
