#include "colors.h"
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
    InitWindow(500, 620, "Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();

    while (WindowShouldClose() == false) // checks for pressed ESC
    {
        game.handleInput();

        if (eventTriggered(0.3))
        {
            game.moveBlockDown();
        }

        BeginDrawing();

        ClearBackground(darkBlue);

        DrawTextEx(font, "Score", {352, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {365, 175}, 38, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "GameOver", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

        game.draw();

        EndDrawing();
    }

    CloseWindow();
}