#include "../include/game.h"

Game::Game(int windowWidth, int windowHeight)
{
    log = Log();
    log.Info("Initializing Game Manager");

    m_windowWidth = windowWidth;
    m_windowHeight = windowHeight;

    camera = Camera2D(Vector2{(float)windowWidth / 2, (float)windowHeight / 2}, Vector2{(float)windowWidth / 2, (float)windowHeight / 2}, 0, 1.2f);

    log.Info("Initializing Island Generator");
    islandGenerator = Island();
    islandGenerator.InitIslandGrid();

    log.Info("Initializing Entity Manager");
    entityManager = Entities();
    entityManager.InitEntityGrid();

    player = Player(camera.target, 38, 38, 100.0f, 2.0f);
}

Game::~Game()
{
    log.Info("Cleaning up Game Manager");
}

void Game::Update()
{
    camera.target = player.position;

    LimitCamera();
}

void Game::Draw()
{
    BeginMode2D(camera);

    islandGenerator.DrawIsland();
    entityManager.DrawEntites();
    player.Draw();

    EndMode2D();
}

void Game::HandleInput()
{
    player.HandleInput();
}

void Game::LimitCamera()
{
    // Gets the total island width and height
    int islandWidth = islandGenerator.GetMapWidth() * islandGenerator.GetCellSize();
    int islandHeight = islandGenerator.GetMapHeight() * islandGenerator.GetCellSize();

    int halfWindowWidth = m_windowWidth / 2;
    int halfWindowHeight = m_windowHeight / 2;

    float targetX = camera.target.x;
    float targetY = camera.target.y;

    // Ensures the camera doesn't go outside the map
    if (targetX - halfWindowWidth < 0)
    {
        // log.Warn("Camera Outside - Left");
        camera.target.x = halfWindowWidth;
    }
    if (targetX + halfWindowWidth > islandWidth)
    {
        // log.Warn("Camera Outside - Right");
        camera.target.x = islandWidth - halfWindowWidth;
    }
    if (targetY - halfWindowHeight < 0)
    {
        // log.Warn("Camera Outside - Up");
        camera.target.y = halfWindowHeight;
    }
    if (targetY + halfWindowHeight > islandHeight)
    {
        // log.Warn("Camera Outside - Down");
        camera.target.y = islandHeight - halfWindowHeight;
    }
}
