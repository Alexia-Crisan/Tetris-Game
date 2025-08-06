#pragma once

#include "colors.h"
#include <map>
#include "position.h"
#include <vector>

class Block
{
private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;

public:
    int id;
    std::map<int, std::vector<Position>> cells;
    Block();
    void draw();
};