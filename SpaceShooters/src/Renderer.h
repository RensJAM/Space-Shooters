#pragma once

#include <iostream>
#include <vector>
#include <sstream>

#include "raylib.h"

#include "Enemies.h"
#include "Player.h"
#include "Levels.h"

class Renderer
{
public:

	static void DrawEnemies();
	static void DrawBullets(float dt);
	static void KillCheck();
	static void DrawGameState();
};