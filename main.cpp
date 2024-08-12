#include <game.h>

int main()
{
    Game g;

    g.Initiate();

    InitWindow(g.screenWidth, g.screenHeight, "Ping Pong!");

    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(g.music);

        BeginDrawing();

        g.update();

        ClearBackground(DARKGREEN);

        g.draw();

        DrawText(TextFormat("%d", g.ball.cpu_score), g.screenWidth / 4 - 20, 20, 80, WHITE);

        DrawText(TextFormat("%d", g.ball.player_score), 3 * g.screenWidth / 4 - 20, 20, 80, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}