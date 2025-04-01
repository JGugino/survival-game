#pragma once
#include "raylib.h"

class Island
{
public:
    enum TileType
    {
        WATER = 0,
        SAND = 1,
        GRASS = 2,
        STONE = 3,
        SNOW = 4
    };

    Island();
    void InitIslandGrid();
    void DrawIsland();
    void DrawIslandGrid();
    void SetMapSize(int width, int height);
    int GetMapWidth();
    int GetMapHeight();
    int GetCellSize();
    int islandGrid[64][64];

private:
    Image m_islandNoiseMap;
    int m_mapWidth, m_mapHeight;
    int m_cellSize;
    void GenerateNewIslandNoiseImage(int offsetX, int offsetY, float scale);
    TileType GetPixelType(Color pixelColor);
    Color GetColorForType(TileType tileType);
};