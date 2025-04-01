#pragma once
#include "raylib.h"

class Entities
{
public:
    enum EntityTypes
    {
        PLAYER = 1,
    };

    int gridWidth, gridHeight;
    int entityGrid[32][20];

    Entities();
    void InitEntityGrid();
    void DrawEntites();
    void DrawEntityGrid();
    bool EntityAtPosition(int x, int y);
    void AddEntityToGrid(int x, int y, EntityTypes entity);
    void MoveEntityToPosition(int currentX, int currentY, int newX, int newY, EntityTypes entity);
};
