#include "../include/island.h"
#include <iostream>

Island::Island()
{
    m_cellSize = 40;
    m_mapWidth = 64;
    m_mapHeight = 64;
    spawnPoint = Vector2{(float)GetRandomValue(0, m_mapWidth * m_cellSize), (float)GetRandomValue(0, m_mapHeight * m_cellSize)};
    GenerateNewIslandNoiseImage(GetRandomValue(0, 100), GetRandomValue(0, 100), 2.0f);
    InitIslandGrid();
}

void Island::InitIslandGrid()
{
    for (int y = 0; y < m_mapHeight - 1; y++)
    {
        for (int x = 0; x < m_mapWidth - 1; x++)
        {
            Color pixelColor = GetImageColor(m_islandNoiseMap, x, y);
            islandGrid[x][y] = GetPixelType(pixelColor);
        }
    }
}

void Island::DrawIsland()
{
    for (int y = 0; y < m_mapHeight; y++)
    {
        for (int x = 0; x < m_mapWidth; x++)
        {
            Color pixelColor = GetImageColor(m_islandNoiseMap, x, y);
            DrawRectangle(x * m_cellSize, y * m_cellSize, m_cellSize, m_cellSize, GetColorForType(GetPixelType(pixelColor)));
        }
    }
}

void Island::DrawIslandGrid()
{
    for (int y = 0; y < m_mapHeight - 1; y++)
    {
        for (int x = 0; x < m_mapWidth - 1; x++)
        {
            std::cout << islandGrid[x][y];
        }
        std::cout << "\n";
    }
}

void Island::SetMapSize(int width, int height)
{
    m_mapWidth = width;
    m_mapHeight = height;
}

void Island::GenerateNewIslandNoiseImage(int offsetX, int offsetY, float scale)
{
    m_islandNoiseMap = GenImagePerlinNoise(m_mapWidth, m_mapHeight, offsetX, offsetY, scale);
}
Island::TileType Island::GetPixelType(Color pixelColor)
{
    int start = 0;
    int incrementor = 51;
    if (pixelColor.r > start && pixelColor.r <= start + (51 * 2)) // WATER
    {
        return TileType::WATER;
    }
    else if (pixelColor.r > start + (51 * 2) && pixelColor.r <= start + (51 * 2) + 10) // SAND
    {
        return TileType::SAND;
    }
    else if (pixelColor.r > start + (51 * 2) + 10 && pixelColor.r <= start + (51 * 3)) // GRASS
    {
        return TileType::GRASS;
    }
    else if (pixelColor.r > start + (51 * 3) && pixelColor.r <= start + (51 * 4)) // STONE
    {
        return TileType::STONE;
    }
    else if (pixelColor.r > start + (51 * 4) && pixelColor.r <= start + (51 * 5)) // SNOW
    {
        return TileType::SNOW;
    }

    return TileType::WATER;
}

Color Island::GetColorForType(Island::TileType tileType)
{
    switch (tileType)
    {
    case TileType::WATER:
        return Color{75, 77, 242, 255};
    case TileType::SAND:
        return Color{242, 212, 135, 255};
    case TileType::GRASS:
        return Color{80, 170, 15, 255};
    case TileType::STONE:
        return Color{164, 165, 164, 255};
    case TileType::SNOW:
        return Color{239, 242, 237, 255};

    default:
        return Color{75, 77, 242, 255};
    }
}

bool Island::IsWalkableTile(int x, int y)
{
    if (islandGrid[x][y] == 0)
    {
        return false;
    }

    return true;
}

void Island::SelectValidSpawnPoint()
{
    //
    int selectedX = GetRandomValue(8, m_mapWidth);
    int selectedY = GetRandomValue(8, m_mapHeight);

    if (IsWalkableTile(selectedX, selectedY))
    {
        spawnPoint = Vector2{(float)selectedX * m_cellSize, (float)selectedY * m_cellSize};
        return;
    }
    else
    {
        SelectValidSpawnPoint();
        return;
    }
}

Vector2 Island::GetSpawnPoint()
{
    return spawnPoint;
}

int Island::GetMapWidth()
{
    return m_mapWidth;
}

int Island::GetMapHeight()
{
    return m_mapHeight;
}

int Island::GetCellSize()
{
    return m_cellSize;
}
