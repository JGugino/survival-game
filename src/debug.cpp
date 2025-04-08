#include "../include/debug.h"
#include <iostream>
#include <format>

void Debug::Draw(Vector2 playerPos, Vector2 worldSpawn, int standingTile)
{
    DrawRectangleRounded(Rectangle{m_offsetX, m_offsetY, 400, 400}, 0.1f, 1, Color{255, 255, 255, 200});
    // FPS
    DrawFPS(m_contentOffsetX, m_contentOffsetY);

    // World Spawn
    DrawText(TextFormat("Spawn - X: %.0f / Y: %.0f", truncf(worldSpawn.x), truncf(worldSpawn.y)), m_contentOffsetX, m_contentOffsetY + m_debugTextSpacing, m_debugFontSize, BLACK);

    // Player Position
    DrawText(TextFormat("Player - X: %.0f / Y: %.0f", truncf(playerPos.x), truncf(playerPos.y)), m_contentOffsetX, m_contentOffsetY + m_debugTextSpacing * 2, m_debugFontSize, BLACK);

    // Mouse Position
    DrawText(TextFormat("Mouse - X: %.0f / Y: %.0f", truncf(GetMouseX()), truncf(GetMouseY())), m_contentOffsetX, m_contentOffsetY + m_debugTextSpacing * 3, m_debugFontSize, BLACK);

    // Standing tile
    const char *tile;

    switch (standingTile)
    {
    case 0:
        tile = "Water";
        break;
    case 1:
        tile = "Sand";
        break;
    case 2:
        tile = "Grass";
        break;
    case 3:
        tile = "Stone";
        break;
    case 4:
        tile = "Snow";
        break;

    default:
        break;
    }

    DrawText(TextFormat("Tile - %s", tile), m_contentOffsetX, m_contentOffsetY + m_debugTextSpacing * 4, m_debugFontSize, BLACK);
}

void Debug::HandleInput()
{
    if (IsKeyPressed(KEY_F3))
    {
        m_debugOpen = !m_debugOpen;
    }
}

bool Debug::DebugOpen() const
{
    return m_debugOpen;
}