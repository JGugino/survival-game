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
    int GetStandingTile() const;
    void GetTileIDAtWorldPosition(int x, int y);
    Vector2 GetSpawnPoint();
    int islandGrid[64][64];

private:
    Vector2 spawnPoint;
    Image m_islandNoiseMap;
    int m_mapWidth, m_mapHeight;
    int m_cellSize;
    int m_standingTile;
    void GenerateNewIslandNoiseImage(int offsetX, int offsetY, float scale);
    TileType GetPixelType(Color pixelColor);
    Color GetColorForType(TileType tileType);
    bool IsWalkableTile(int x, int y);
    void SelectValidSpawnPoint();
};