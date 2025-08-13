#pragma once
#include <vector>
#include <iostream>

#include "raylib.h"

struct EnemyData {
    float x, y;
    int width, height;
    Color color;
    float moveSpeed;
};

class Enemies {
public:
    static std::vector<EnemyData> enemyList;

    static void Spawn(int totalEnemies, float spawnRateSeconds, float fireRate, float moveSpeed);

    static void Update(float dt);

private:
    static void SpawnOne();

    static int enemiesRemaining;
    static float spawnTimer;
    static float spawnInterval;
    static float enemyFireRate;
    static float enemyMoveSpeed;
    static double pathMiddle;
};
