#include "Renderer.h"

double currentTime;

void Renderer::DrawEnemies()
{
    currentTime = GetTime();
        for (auto& enemy : Enemies::enemyList) {

		DrawRectangle(enemy.x, enemy.y, enemy.width, enemy.height, enemy.color);
	};
}

void Renderer::DrawBullets(float dt)
{
    for (auto& bullet : bullets)
    {
        DrawRectangle(bullet.x, bullet.y, 30, 10, GOLD);
        bullet.x += bullet.speed * dt;
    }

    auto it = std::remove_if(
        bullets.begin(),
        bullets.end(),
        [](const Bullet& bullet) {
            return bullet.x > 1280;
        }
    );

    bullets.erase(it, bullets.end());
}

void Renderer::KillCheck()
{
    for (int b = (int)bullets.size() - 1; b >= 0; b--)
    {
        bool bulletHit = false;

        for (int e = (int)Enemies::enemyList.size() - 1; e >= 0; e--)
        {
            Rectangle bulletRect = { bullets[b].x, bullets[b].y, 30, 10 };
            Rectangle enemyRect = { Enemies::enemyList[e].x, Enemies::enemyList[e].y,
                (float)Enemies::enemyList[e].width,
                (float)Enemies::enemyList[e].height };

            if (CheckCollisionRecs(bulletRect, enemyRect))
            {
                Enemies::enemyList.erase(Enemies::enemyList.begin() + e);

                bullets.erase(bullets.begin() + b);
                bulletHit = true;
                break;
            }
        }
    }
}

void Renderer::DrawGameState()
{
    int spacing = 1;
    std::stringstream ss;
    ss << "Level: " << Level::currentLevel;
    if (Level::currentLevel >= 100)
    {
        if (Level::currentLevel == Level::LEVEL_WON)
        {
            std::string text1 = "YOU WON, CONGRATS";
            const char* charText1 = text1.c_str();
            Vector2 size1 = MeasureTextEx(GetFontDefault(), charText1, 30, spacing);
            float x = (GetScreenWidth() - size1.x) / 2;
            DrawTextEx(GetFontDefault(), charText1, Vector2{ x, 10 }, 30, spacing, WHITE);
        }
        if (Level::currentLevel == Level::LEVEL_LOST)
        {
            std::string text2 = "YOU LOST, GAME OVER";
            const char* charText2 = text2.c_str();
            Vector2 size2 = MeasureTextEx(GetFontDefault(), charText2, 30, spacing);
            float x = (GetScreenWidth() - size2.x) / 2;
            DrawTextEx(GetFontDefault(), charText2, Vector2{ x, 10 }, 30, spacing, WHITE);
        }
    }
    else
    {
        std::string text = ss.str();
        const char* charText = text.c_str();

        Vector2 size = MeasureTextEx(GetFontDefault(), charText, 30, spacing);

        float x = (GetScreenWidth() - size.x) / 2;

        DrawTextEx(GetFontDefault(), charText, Vector2{ x, 10 }, 30, spacing, WHITE);
    }
}
