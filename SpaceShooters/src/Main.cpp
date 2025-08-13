#include "raylib.h"

#include "Player.h"
#include "Levels.h"
#include "Renderer.h"

std::vector<Bullet> bullets;

//  TODO-LIST:
//  Game Loop (Enter to play again)
//  UI Feedback (Current level, 
//
//

int main(void)
{
    InitWindow(1280, 720, "Space Shooters");
    SetTargetFPS(120);

    Player player;

    bool gameStarted = false;

    Level::currentLevel = Level::LEVEL_1;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(DARKGRAY);

        for (int i = 0; i <= 7; i++)
        {
            DrawLineEx({ 0, (720 / 7.0f * i) }, { 1280, (720 / 7.0f * i) }, 2.5f, BLACK);
        }
        DrawLineEx({ 100, 0 }, { 100, 720 }, 2.5f, RED);

        if (!gameStarted && IsKeyPressed(KEY_ENTER))
        {
            WaitTime(1);
            gameStarted = true;
            Level::Start();
        }
        if (IsKeyPressed(KEY_W))
            player.MoveUp();
        if (IsKeyPressed(KEY_S))
            player.MoveDown();
        if (IsKeyPressed(KEY_UP))
            player.MoveUp();
        if (IsKeyPressed(KEY_DOWN))
            player.MoveDown();
        if (IsKeyPressed(KEY_SPACE))
            player.Shoot();

        Enemies::Update(dt);

        Renderer::KillCheck();
        player.Draw();
        Renderer::DrawEnemies();
        Renderer::DrawBullets(dt);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}