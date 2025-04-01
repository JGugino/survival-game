#pragma once
#include "./entity.h"

class Player : public Entity
{
public:
    Player();
    Player(Vector2 position, int width, int height, float health, float speed);
    void HandleInput();
    void Draw();
    float GetHealth();
    int GetWidth();
    int GetHeight();

private:
    enum Direction
    {
        UP = 0,
        DOWN = 1,
        LEFT = 2,
        RIGHT = 3
    };

    int width, height;
    float health;
    float speed;
    Direction facingDirection;
};