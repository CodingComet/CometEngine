#pragma once
#include <GLM/glm.hpp>

constexpr auto MAX_BUTTONS = 32;

class Mouse
{
public:
    Mouse();
    ~Mouse();

    void update();
    int get_button(int button) const { return buttons[button]; };

private:
    int buttons[MAX_BUTTONS];
    double xpos, ypos;

    glm::vec2 scroll_deltas;
    glm::vec2 cursor_position_deltas;
};
