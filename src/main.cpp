#include "game.h"
#include <raylib.h>

int main()
{
    Color darkBlue = {44, 44, 127, 255};

    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false) // checks for pressed ESC
    {
        game.handleInput();

        BeginDrawing();
        ClearBackground(darkBlue);

        game.draw();

        EndDrawing();
    }

    CloseWindow();
}