#pragma once

#include <raylib.h>
#include <vector>

class Grid
{
private:
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
    std::vector<Color> getCellColors();

public:
    int grid[20][10];
    Grid();
    void initialize();
    void print();
    void draw();
};