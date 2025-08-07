#include "game.h"
#include <raylib.h>

double lastUpdateTime = 0;

bool eventTriggered(double interval)
{
    double currentTime = GetTime();

    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }

    return false;
}

int main()
{
    Color darkBlue = {44, 44, 127, 255};

    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false) // checks for pressed ESC
    {
        game.handleInput();

        if (eventTriggered(0.02))
        {
            game.moveBlockDown();
        }

        BeginDrawing();
        ClearBackground(darkBlue);

        game.draw();

        EndDrawing();
    }

    CloseWindow();
}