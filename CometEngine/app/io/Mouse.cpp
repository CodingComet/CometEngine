#include "Mouse.h"

Mouse::Mouse()
{
}

Mouse::~Mouse()
{
}

void Mouse::update()
{
    scroll_deltas = {0, 0};
    cursor_position_deltas = {0, 0};
}
