#pragma once

#include "blocks.cpp"
#include "grid.h"

class Game
{
private:
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    bool isBlockOutside();
    void rotateBlock();
    void lockBlock();
    bool blockFits();

public:
    Grid grid;
    Game();
    Block getRandomBlock();
    std::vector<Block> getAllBlocks();
    void draw();
    void handleInput();
    void moveBlockLeft();
    void moveBlockRight();
    void moveBlockDown();
};