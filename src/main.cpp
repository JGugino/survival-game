#include "raylib.h"
#include "../include/game.h"

int main()
{

  const char *windowTitle = "Survival Game - Raylib C++";
  const int windowWidth{1280};
  const int windowHeight{800};
  const int targetFPS{60};

  InitWindow(windowWidth, windowHeight, windowTitle);
  SetTargetFPS(targetFPS);

  Game gameManager{Game(windowWidth, windowHeight)};

  while (!WindowShouldClose())
  {
    gameManager.HandleInput();

    gameManager.Update();

    BeginDrawing();

    ClearBackground(WHITE);

    gameManager.Draw();

    EndDrawing();
  }

  CloseWindow();
}
