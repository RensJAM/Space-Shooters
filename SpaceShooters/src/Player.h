#pragma once

#include "raylib.h"
#include <iostream>
#include <vector>


struct Bullet
{
	float x, y, speed;
	float scale = 1.0f;
};
extern std::vector<Bullet> bullets;

class Player
{
public:
	float posX;
	float posY;
	int frameIndex;
	Texture2D shipTexture;

	Player();
	~Player();

	void Draw() const;
	void MoveUp();
	void MoveDown();
	void Shoot() const;
	
};