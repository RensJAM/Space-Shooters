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

	static void DrawEnemies(float dt, Texture2D alienTexture);
	static void DrawBullets(float dt, Texture2D bulletTexture);
	static void KillCheck();
	static void DrawGameState();
};