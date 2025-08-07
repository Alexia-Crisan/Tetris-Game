#include "colors.h"
#include "grid.h"
#include <iostream>

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    colors = getCellColors();

    initialize();
}

void Grid::initialize()
{
    int row, column;
    for (row = 0; row < numRows; row++)
    {
        for (column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;
        }
    }
}

void Grid::print()
{
    int row, column;
    for (row = 0; row < numRows; row++)
    {
        for (column = 0; column < numCols; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << "\n";
    }
}

void Grid::draw()
{
    int row, column;
    for (row = 0; row < numRows; row++)
    {
        for (column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column];

            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::isCellOutside(int row, int column)
{
    if (row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false;
    }

    return true;
}

bool Grid::isCellEmpty(int row, int column)
{
    if (grid[row][column] == 0)
    {
        return true;
    }

    return false;
}

bool Grid::isRowFull(int row)
{
    int column;
    for (column = 0; column < numCols; column++)
    {
        if (grid[row][column] == 0)
        {
            return false;
        }
    }

    return true;
}

void Grid::clearRow(int row)
{
    int column;
    for (column = 0; column < numCols; column++)
    {
        grid[row][column] = 0;
    }
}

void Grid::moveRowDown(int row, int numRows)
{
    int column;
    for (column = 0; column < numCols; column++)
    {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}

int Grid::clearFullRows()
{
    int row, completed = 0;

    for (row = numRows - 1; row >= 0; row--)
    {
        if (isRowFull(row))
        {
            completed++;
            clearRow(row);
        }
        else if (completed > 0)
        {
            moveRowDown(row, completed);
        }
    }

    return completed;
}