#include "../include/inventory.h"
#include <iostream>
#include <raylib.h>

Inventory::Inventory()
{
    cellSize = 48;
    ClearInventory();
    ClearHotbar();
}

void Inventory::DrawInventory(int windowWidth, int windowHeight)
{
    float inventoryWidth = inventory.containerWidth * cellSize;
    float inventoryHeight = inventory.containerHeight * cellSize;

    float offsetX = (windowWidth - inventoryWidth) / 2;
    float offsetY = (windowHeight - inventoryHeight) / 2;

    DrawRectangleRounded(Rectangle{offsetX, offsetY, inventoryWidth, inventoryHeight}, 0.1f, 1, WHITE);

    for (int y = 0; y < inventory.containerHeight; y++)
    {
        for (int x = 0; x < inventory.containerWidth; x++)
        {
            DrawRectangleRoundedLines(Rectangle{(float)x * cellSize + offsetX, (float)y * cellSize + offsetY, (float)cellSize, (float)cellSize}, 0.4f, 1, BLACK);
        }
    }
}

void Inventory::DrawHotbar(int windowWidth, int windowHeight)
{
    float offsetX = 10.0f;
    float offsetY = 10.0f;

    DrawRectangleRounded(Rectangle{offsetX, offsetY, (float)hotbarSize * cellSize, (float)cellSize}, 0.1f, 1, WHITE);

    for (int i = 0; i < hotbarSize; i++)
    {
        DrawRectangleRoundedLines(Rectangle{(float)i * cellSize + offsetX, offsetY, (float)cellSize, (float)cellSize}, 0.4f, 1, BLACK);
    }
}

void Inventory::DrawInventoryToConsole()
{
    std::cout << "###INVENTORY###\n";
    for (int y = 0; y < inventory.containerHeight; y++)
    {
        for (int x = 0; x < inventory.containerWidth; x++)
        {
            std::cout << inventory.itemGrid[x][y];
        }
        std::cout << "\n";
    }
}

void Inventory::DrawHotbarToConsole()
{
    std::cout << "###HOTBAR###\n";
    for (int i = 0; i < hotbarSize; i++)
    {
        std::cout << hotbar[i];
    }
    std::cout << "\n";
}

void Inventory::ClearInventory()
{
    for (int x = 0; x < inventory.containerWidth; x++)
    {
        for (int y = 0; y < inventory.containerHeight; y++)
        {
            inventory.itemGrid[x][y] = Items::EMPTY;
        }
    }
}

void Inventory::ClearHotbar()
{
    for (int i = 0; i < hotbarSize; i++)
    {
        hotbar[i] = Items::EMPTY;
    }
}

void Inventory::HandleInput()
{
    if (IsKeyPressed(KEY_TAB))
    {
        inventoryVisible = !inventoryVisible;
    }
}

bool Inventory::InventoryVisible()
{
    return inventoryVisible;
}