#include "../include/player.h"
#include "raylib.h"
#include <iostream>

Player::Player() {}

Player::Player(Vector2 position, int width, int height, float health, float speed)
{
    this->position = position;
    this->width = width;
    this->height = height;
    this->health = health;
    this->speed = speed;
    facingDirection = Direction::UP;
    moving = false;
}

void Player::Draw()
{
    DrawRectangle(position.x, position.y, width, height, YELLOW);
}

void Player::Update(int islandWidth, int islandHeight)
{
    // std::cout << "X: " << position.x << "\n";
    // std::cout << "Y: " << position.y << "\n";

    // Limit player in X direction
    if (position.x <= 0)
    {
        std::cout << "x < 0 \n";
        position.x = 0;
    }
    if (position.x >= islandWidth - width)
    {
        std::cout << "x > width \n";
        position.x = islandWidth - width;
    }

    // Limit player in Y direction
    if (position.y <= 0)
    {
        std::cout << "y < 0 \n";
        position.y = 0;
    }
    if (position.y >= islandHeight - height)
    {
        std::cout << "x > height \n";
        position.y = islandHeight - height;
    }
}

void Player::HandleInput()
{
    if (IsKeyDown(KEY_W))
    {
        position.y -= speed;
        facingDirection = Direction::UP;
        moving = true;
    }
    else if (IsKeyDown(KEY_A))
    {
        position.x -= speed;
        facingDirection = Direction::LEFT;
        moving = true;
    }
    else if (IsKeyDown(KEY_S))
    {
        position.y += speed;
        facingDirection = Direction::DOWN;
        moving = true;
    }
    else if (IsKeyDown(KEY_D))
    {
        position.x += speed;
        facingDirection = Direction::RIGHT;
        moving = true;
    }
    else
    {
        if (moving)
        {
            moving = false;
        }
    }
}

bool Player::IsMoving()
{
    return moving;
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