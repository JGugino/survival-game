#pragma once
#include "raylib.h"
#include "player.h"
#include <math.h>

class Debug
{
public:
    Debug() : m_debugOpen(false),
              m_offsetX(GetScreenWidth() - 440),
              m_offsetY(10),
              m_contentOffsetX(m_offsetX + 20),
              m_contentOffsetY(m_offsetY + 20),
              m_debugFontSize(20.0f),
              m_debugTextSpacing(30.0f) {};
    void Draw(Vector2 playerPos, Vector2 worldSpawn, int standingTile);
    void HandleInput();
    bool DebugOpen() const;

private:
    bool m_debugOpen;
    float m_debugFontSize;
    float m_debugTextSpacing;
    float m_offsetX;
    float m_offsetY;
    float m_contentOffsetX;
    float m_contentOffsetY;
};