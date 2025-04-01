#include "../include/player.h"
#include "raylib.h"

Player::Player() {}

Player::Player(Vector2 position, int width, int height, float health, float speed)
{
    this->position = position;
    this->width = width;
    this->height = height;
    this->health = health;
    this->speed = speed;
    facingDirection = Direction::UP;
}

void Player::Draw()
{
    DrawRectangle(position.x, position.y, width, height, YELLOW);
}

void Player::HandleInput()
{
    if (IsKeyDown(KEY_W))
    {
        position.y -= speed;
        facingDirection = Direction::UP;
    }
    else if (IsKeyDown(KEY_A))
    {
        position.x -= speed;
        facingDirection = Direction::LEFT;
    }
    else if (IsKeyDown(KEY_S))
    {
        position.y += speed;
        facingDirection = Direction::DOWN;
    }
    else if (IsKeyDown(KEY_D))
    {
        position.x += speed;
        facingDirection = Direction::RIGHT;
    }
}

// GETTERS
float Player::GetHealth()
{
    return health;
}

int Player::GetWidth()
{
    return width;
}

int Player::GetHeight()
{
    return height;
}