#include "../include/inventory.h"
#include <iostream>
#include <raylib.h>

const Color transparentWhite = Color{255, 255, 255, 230};

Inventory::Inventory()
{
    cellSize = 48;
    selectedHotbarSlot = 0;
    inventoryVisible = false;
    ClearInventory();
    ClearHotbar();
}

void Inventory::DrawInventory(int windowWidth, int windowHeight)
{
    float inventoryWidth = inventory.containerWidth * cellSize;
    float inventoryHeight = inventory.containerHeight * cellSize;

    float offsetX = (windowWidth - inventoryWidth) / 2;
    float offsetY = (windowHeight - inventoryHeight) / 2;

    // Inventory background
    DrawRectangleRounded(Rectangle{offsetX, offsetY - 40, inventoryWidth + 10, inventoryHeight + 100}, 0.1f, 1, transparentWhite);

    // Inventory slots
    for (int y = 0; y < inventory.containerHeight; y++)
    {
        for (int x = 0; x < inventory.containerWidth; x++)
        {
            DrawRectangleRoundedLines(Rectangle{(float)x * cellSize + offsetX + 5, (float)y * cellSize + offsetY + 55, (float)cellSize, (float)cellSize}, 0.6f, 1, BLACK);
        }
    }
}

void Inventory::DrawHotbar(int windowWidth, int windowHeight)
{
    float offsetX = 10.0f;
    float offsetY = 10.0f;

    // Hotbar background
    DrawRectangleRounded(Rectangle{offsetX, offsetY, (float)hotbarSize * cellSize + 10, (float)cellSize + 10}, 0.1f, 1, transparentWhite);

    // Hotbar slots
    for (int i = 0; i < hotbarSize; i++)
    {
        DrawRectangleRoundedLines(Rectangle{(float)i * cellSize + offsetX + 5, offsetY + 5, (float)cellSize, (float)cellSize}, 0.4f, 1, BLACK);
        if (selectedHotbarSlot == i)
        {
            DrawRectangleRoundedLinesEx(Rectangle{(float)i * cellSize + offsetX + 5, offsetY + 5, (float)cellSize, (float)cellSize}, 0.4f, 1, 3, BLACK);
        }
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
    // Toggle inventory
    if (IsKeyPressed(KEY_TAB))
    {
        inventoryVisible = !inventoryVisible;
    }

    HotbarInputHandler();
}

void Inventory::HotbarInputHandler()
{
    // Hotbar scrollwheel input
    if (GetMouseWheelMove() > 0)
    {
        selectedHotbarSlot++;
        if (selectedHotbarSlot > 8)
        {
            selectedHotbarSlot = 8;
        }
    }
    else if (GetMouseWheelMove() < 0)
    {
        selectedHotbarSlot--;
        if (selectedHotbarSlot < 0)
        {
            selectedHotbarSlot = 0;
        }
    }

    // Hotbar shortcuts
    if (IsKeyPressed(KEY_ONE))
    {
        selectedHotbarSlot = 0;
    }
    else if (IsKeyPressed(KEY_TWO))
    {
        selectedHotbarSlot = 1;
    }
    else if (IsKeyPressed(KEY_THREE))
    {
        selectedHotbarSlot = 2;
    }
    else if (IsKeyPressed(KEY_FOUR))
    {
        selectedHotbarSlot = 3;
    }
    else if (IsKeyPressed(KEY_FIVE))
    {
        selectedHotbarSlot = 4;
    }
    else if (IsKeyPressed(KEY_SIX))
    {
        selectedHotbarSlot = 5;
    }
    else if (IsKeyPressed(KEY_SEVEN))
    {
        selectedHotbarSlot = 6;
    }
    else if (IsKeyPressed(KEY_EIGHT))
    {
        selectedHotbarSlot = 7;
    }
    else if (IsKeyPressed(KEY_NINE))
    {
        selectedHotbarSlot = 8;
    }
}

bool Inventory::InventoryVisible()
{
    return inventoryVisible;
}