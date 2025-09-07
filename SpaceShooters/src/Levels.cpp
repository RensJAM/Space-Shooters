#include "Levels.h"
#include "Enemies.h"

#include <iostream>

void Level1();
void Level2();
void Level3();
void Level4();
void Level5();
void Level6();
void Level7();
void Level8();
void Level9();
void Level10();

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
		Level3();
		break;
	case LEVEL_4:
		Level4();
		break;
	case LEVEL_5:
		Level5();
		break;
	case LEVEL_6:
		Level6();
		break;
	case LEVEL_7:
		Level7();
		break;
	case LEVEL_8:
		Level8();
		break;
	case LEVEL_9:
		Level9();
		break;
	case LEVEL_10:
		Level10();
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
	int enemies = 40;
	float spawnRate = 0.7f;
	float fireRate = 0.6f;
	int moveSpeed = 300.0f;
	Enemies::Spawn(enemies, spawnRate, fireRate, moveSpeed);
}

void Level3()
{
	int enemies = 30;
	float spawnRate = 0.35f;
	float fireRate = 1.2f;
	int moveSpeed = 170.0f;
	Enemies::Spawn(enemies, spawnRate, fireRate, moveSpeed);
}

void Level4()
{
	int enemies = 7;
	float spawnRate = 0.4f;
	float fireRate = 1.2f;
	int moveSpeed = 450.0f;
	Enemies::Spawn(enemies, spawnRate, fireRate, moveSpeed);
}

void Level5()
{
	int enemies = 50;
	float spawnRate = 0.25f;
	float fireRate = 0.8f;
	int moveSpeed = 200.0f;
	Enemies::Spawn(enemies, spawnRate, fireRate, moveSpeed);
}

void Level6()
{
	int enemies = 20;
	float spawnRate = 0.6f;
	float fireRate = 1.5f;
	int moveSpeed = 380.0f;
	Enemies::Spawn(enemies, spawnRate, fireRate, moveSpeed);
}

void Level7()
{
	int enemies = 20;
	float spawnRate = 0.2f;
	float fireRate = 0.5f;
	int moveSpeed = 250.0f;
	Enemies::Spawn(enemies, spawnRate, fireRate, moveSpeed);
}

void Level8()
{
	int enemies = 5;
	float spawnRate = 0.8f;
	float fireRate = 2.0f;
	int moveSpeed = 500.0f;
	Enemies::Spawn(enemies, spawnRate, fireRate, moveSpeed);
}

void Level9()
{
	int enemies = 60;
	float spawnRate = 0.3f;
	float fireRate = 1.0f;
	int moveSpeed = 270.0f;
	Enemies::Spawn(enemies, spawnRate, fireRate, moveSpeed);
}

void Level10()
{
	int enemies = 100;
	float spawnRate = 0.15f;
	float fireRate = 0.4f;
	int moveSpeed = 320.0f;
	Enemies::Spawn(enemies, spawnRate, fireRate, moveSpeed);
}