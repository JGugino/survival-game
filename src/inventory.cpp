#include "../include/inventory.h"
#include <iostream>
#include <raylib.h>

const Color transparentWhite = Color{255, 255, 255, 230};

Inventory::Inventory()
{
    cellSize = 48;
    selectedHotbarSlot = 0;
    inventoryVisible = false;

    // Inventory alignment settings
    inventoryHeightOffset = 40;
    inventoryWidthPadding = 10;
    inventoryHeightPadding = 100;
    inventoryCellWidthOffset = 5;
    inventoryCellHeightOffset = 55;

    // Hotbar alignement settings
    hotbarHeightOffset = 10;
    hotbarWidthOffset = 10;
    hotbarWidthPadding = 10;
    hotbarHeightPadding = 10;
    hotbarCellWidthOffset = 5;
    hotbarCellHeightOffset = 5;

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
    DrawRectangleRounded(Rectangle{offsetX, offsetY - inventoryHeightOffset, inventoryWidth + inventoryWidthPadding, inventoryHeight + inventoryHeightPadding}, 0.1f, 1, transparentWhite);

    // Inventory slots
    for (int y = 0; y < inventory.containerHeight; y++)
    {
        for (int x = 0; x < inventory.containerWidth; x++)
        {
            DrawRectangleRoundedLines(Rectangle{(float)x * cellSize + offsetX + inventoryCellWidthOffset, (float)y * cellSize + offsetY + inventoryCellHeightOffset, (float)cellSize, (float)cellSize}, 0.6f, 1, BLACK);
        }
    }
}

void Inventory::DrawHotbar(int windowWidth, int windowHeight)
{

    // Hotbar background
    DrawRectangleRounded(Rectangle{(float)hotbarWidthOffset, (float)hotbarHeightOffset, (float)hotbarSize * cellSize + hotbarWidthPadding, (float)cellSize + hotbarHeightPadding}, 0.1f, 1, transparentWhite);

    // Hotbar slots
    for (int i = 0; i < hotbarSize; i++)
    {
        DrawRectangleRoundedLines(Rectangle{(float)i * cellSize + (float)hotbarWidthOffset + hotbarCellWidthOffset, (float)hotbarHeightOffset + hotbarCellHeightOffset, (float)cellSize, (float)cellSize}, 0.4f, 1, BLACK);
        if (selectedHotbarSlot == i)
        {
            DrawRectangleRoundedLinesEx(Rectangle{(float)i * cellSize + (float)hotbarWidthOffset + hotbarCellWidthOffset, (float)hotbarHeightOffset + hotbarCellHeightOffset, (float)cellSize, (float)cellSize}, 0.4f, 1, 3, BLACK);
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