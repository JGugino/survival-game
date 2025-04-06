#pragma once
#include "./items.h"

struct Container
{
    int containerWidth = 9;
    int containerHeight = 4;
    Items itemGrid[9][4];
};
