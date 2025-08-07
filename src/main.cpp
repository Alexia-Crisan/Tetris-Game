#include "blocks.cpp"
#include "grid.h"
#include <raylib.h>

int main()
{
    Color darkBlue = {44, 44, 127, 255};

    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();

    TBlock block = TBlock();

    while (WindowShouldClose() == false) // checks for pressed ESC
    {
        BeginDrawing();
        ClearBackground(darkBlue);

        grid.draw();
        block.draw();

        EndDrawing();
    }

    CloseWindow();
}