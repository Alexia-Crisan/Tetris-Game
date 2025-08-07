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

public:
    int grid[20][10];
    Grid();
    void initialize();
    void print();
    void draw();
    bool isCellOutside(int row, int column);
    bool isCellEmpty(int row, int column);
};