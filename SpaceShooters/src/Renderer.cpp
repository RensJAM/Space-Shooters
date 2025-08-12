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
            return bullet.x > 1280; // TODO: If collide with enemy (! 1280)
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
