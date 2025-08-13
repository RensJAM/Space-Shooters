#pragma once

#include "raylib.h"
#include <iostream>
#include <vector>

struct Bullet
{
	float x, y, speed;
};
extern std::vector<Bullet> bullets;

class Player
{
public:
	float posX;
	float posY;

	Player();
	~Player();

	void Draw() const;

	void MoveUp();

	void MoveDown();

	void Shoot() const;
	
};