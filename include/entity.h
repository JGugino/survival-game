#pragma once
#include "raylib.h"

class Entity
{
public:
    Vector2 position;
    int width, height;
    void Move(int x, int y);
};