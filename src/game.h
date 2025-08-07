#pragma once

#include "blocks.cpp"
#include "grid.h"

class Game
{
private:
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Grid grid;
    bool isBlockOutside();
    void rotateBlock();
    void lockBlock();
    bool blockFits();
    void reset();
    Block getRandomBlock();
    std::vector<Block> getAllBlocks();
    void moveBlockLeft();
    void moveBlockRight();

public:
    Game();
    bool gameOver;
    int score;
    void draw();
    void handleInput();
    void moveBlockDown();
    void updateScore(int linesCleared, int moveDownPoints);
};