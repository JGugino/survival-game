#include "../include/entities.h"
#include <iostream>

Entities::Entities()
{
    gridWidth = 32;
    gridHeight = 20;
}

void Entities::InitEntityGrid()
{
    for (int y = 0; y < gridHeight; y++)
    {
        for (int x = 0; x < gridWidth; x++)
        {
            entityGrid[x][y] = 0;
        }
    }
}

void Entities::DrawEntites()
{
    for (int y = 0; y < gridHeight - 1; y++)
    {
        for (int x = 0; x < gridWidth - 1; x++)
        {
            if (entityGrid[x][y] == EntityTypes::PLAYER)
            {
                // std::cout << "X: " << x << ", Y: " << y << "\n";
                DrawRectangle(x * 40, y * 40, 40, 40, PURPLE);
            }
        }
    }
}

void Entities::DrawEntityGrid()
{
    for (int y = 0; y < gridHeight; y++)
    {
        for (int x = 0; x < gridWidth; x++)
        {
            std::cout << entityGrid[x][y];
        }
        std::cout << "\n";
    }
}

bool Entities::EntityAtPosition(int x, int y)
{
    if (entityGrid[x][y] == 0)
    {
        return false;
    }
    return true;
}

void Entities::AddEntityToGrid(int x, int y, EntityTypes entity)
{
    // std::cout << "X: " << x << ", Y: " << y << "\n";
    if (!EntityAtPosition(x, y))
    {
        entityGrid[x][y] = entity;
        DrawEntityGrid();
    }
}

void Entities::MoveEntityToPosition(int currentX, int currentY, int newX, int newY, EntityTypes entity)
{
    if (!EntityAtPosition(newY, newX))
    {
        entityGrid[currentX][currentY] = 0;
        entityGrid[newX][newY] = entity;
    }
}
