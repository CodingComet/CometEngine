#pragma once
#include <bitset>

constexpr auto MAX_KEYS = 1024; // SHOULD LOOK INTO THIS 

class Keyboard
{
public:
    Keyboard();
    ~Keyboard();

    int get_key(int key) const noexcept;
    void set_key(int key, int action) noexcept;
    
private:
    int keys[MAX_KEYS]; // should maybe unsigned char? or bitset
};

