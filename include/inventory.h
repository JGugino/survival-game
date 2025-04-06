#pragma once
#include "./container.h"

class Inventory
{
public:
    Inventory();
    void DrawInventory(int windowWidth, int windowHeight);
    void DrawHotbar(int windowWidth, int windowHeight);
    void DrawInventoryToConsole();
    void DrawHotbarToConsole();
    void HandleInput();
    bool InventoryVisible();

private:
    const int hotbarSize = 9;
    Container inventory;
    Items hotbar[9];
    int cellSize;
    int selectedHotbarSlot;
    bool inventoryVisible;
    void ClearInventory();
    void ClearHotbar();
    void HotbarInputHandler();
};