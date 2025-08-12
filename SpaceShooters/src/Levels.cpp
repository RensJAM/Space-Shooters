#include "Levels.h"
#include "Enemies.h"

#include <iostream>

void Level1();
void Level2();
void Level3();

int Level::currentLevel = Level::LEVEL_1;

void Level::Start()
{
	switch (currentLevel)
	{
	case LEVEL_1:
		Level1();
		break;
	case LEVEL_2:
		Level2();
		break;
	case LEVEL_3:
		Level2();
		break;
	default: std::cout << "Failed to load levels!" << std::endl;
	}
}

void Level1()
{
	int enemies = 10;
	float spawnRate = 1.0f;
	float fireRate = 0.7f;
	int moveSpeed = 350.0f;
	Enemies::Spawn(enemies, spawnRate, fireRate, moveSpeed);
}

void Level2()
{
	int enemies = 30;
	float spawnRate = 0.7f;
	float fireRate = 0.6f;
	int moveSpeed = 300.0f;
	Enemies::Spawn(enemies, spawnRate, fireRate, moveSpeed);
}

void Level3()
{
	int enemies = 50;
	float spawnRate = 0.3f;
	float fireRate = 1.2f;
	int moveSpeed = 400.0f;
}