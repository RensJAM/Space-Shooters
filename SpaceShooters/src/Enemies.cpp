#include "Enemies.h"
#include "Levels.h"

#include "raylib.h"

std::vector<EnemyData> Enemies::enemyList;
int    Enemies::enemiesRemaining = 0;
float  Enemies::spawnTimer = 0.0f;
float  Enemies::spawnInterval = 1.0f;
float  Enemies::enemyFireRate = 0.7f;
float  Enemies::enemyMoveSpeed = 100.0f; // Pixels/s
double Enemies::pathMiddle = (720 / 7) / 2 - 20;

bool started = false;
bool gameOver = false;

void Enemies::Spawn(int totalEnemies, float spawnRateSeconds, float fireRate, float moveSpeed)
{
    enemiesRemaining = totalEnemies;
    spawnInterval = spawnRateSeconds;
    enemyFireRate = fireRate;
    enemyMoveSpeed = moveSpeed;
    spawnTimer = 0.0f;

    if (spawnInterval <= 0.0f) {
        for (int i = 0; i < enemiesRemaining; ++i) SpawnOne();
        enemiesRemaining = 0;
    }
}

void Enemies::SpawnOne()
{
    float x = 1400.0f;
    int path = GetRandomValue(0, 6);
    float y = (720.0f / 7.0f) * path + pathMiddle;

    started = true;

    EnemyData e;
    e.x = x;
    e.y = y;
    e.width = 40;
    e.height = 40;
    e.color = RED;
    e.moveSpeed = enemyMoveSpeed;

    enemyList.push_back(e);
}

void Enemies::Update(float dt)
{
    if (enemiesRemaining > 0 && spawnInterval > 0.0f) {
        spawnTimer += dt;

        while (enemiesRemaining > 0 && spawnTimer >= spawnInterval) {
            spawnTimer -= spawnInterval;
            SpawnOne();
            --enemiesRemaining;
        }
    }

    for (auto& e : enemyList)
    {
        e.x -= e.moveSpeed * dt;
    }

    if (!gameOver)
    {
        for (auto& enemy : enemyList)
        {
            if (enemy.x <= 60)
            {
                gameOver = true;
                Level::currentLevel = Level::LEVEL_LOST;
            }
        }
    }

    if (gameOver && Level::currentLevel == Level::LEVEL_1)
        gameOver = false;

    enemyList.erase(
        std::remove_if(enemyList.begin(), enemyList.end(),
            [](const EnemyData& en) { return en.x + en.width < 0.0f; }),
        enemyList.end()
    );

    if (!gameOver && enemyList.empty())
    {
        if (enemiesRemaining == 0 && started == true)
        {
            if (Level::currentLevel == Level::LEVEL_1)
            {
                started = false;
                Level::currentLevel = Level::LEVEL_2;
                Level::Start();
            }
            else if (Level::currentLevel == Level::LEVEL_2)
            {
                started = false;
                Level::currentLevel = Level::LEVEL_3;
                Level::Start();
            }
            else if (Level::currentLevel == Level::LEVEL_3)
            {
                started = false;
                Level::currentLevel = Level::LEVEL_4;
                Level::Start();
            }
            else if (Level::currentLevel == Level::LEVEL_4)
            {
                started = false;
                Level::currentLevel = Level::LEVEL_WON;
            }
        }
    }
}