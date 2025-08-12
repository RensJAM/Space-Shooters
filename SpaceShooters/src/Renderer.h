#pragma once

#include <iostream>
#include <vector>

#include "raylib.h"

#include "Enemies.h"
#include "Player.h"

class Renderer
{
public:

	static void DrawEnemies();
	static void DrawBullets(float dt);
	static void KillCheck();
};