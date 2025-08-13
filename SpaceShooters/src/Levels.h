#pragma once


class Level
{
public:
	enum Levels
	{
		LEVEL_1 = 1,
		LEVEL_2,
		LEVEL_3,
		LEVEL_4,

		LEVEL_WON = 100,
		LEVEL_LOST = 101
	};

	static int currentLevel;

	static void Start();
};
