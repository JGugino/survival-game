#pragma once
#include "log.h"
#include "island.h"
#include "entities.h"
#include "player.h"
#include "./inventory.h"

class Game
{
public:
    Game(int windowWidth, int windowHeight);
    ~Game();
    void Update();
    void Draw();
    void HandleInput();
    void LimitCamera();
    Log log;

private:
    int m_windowWidth, m_windowHeight;
    Camera2D camera;
    Island islandGenerator;
    Entities entityManager;
    Player player = Player();
    Inventory inventory = Inventory();
};