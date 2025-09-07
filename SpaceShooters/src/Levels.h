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
		LEVEL_5,
		LEVEL_6,
		LEVEL_7,
		LEVEL_8,
		LEVEL_9,
		LEVEL_10,

		LEVEL_WON = 100,
		LEVEL_LOST = 101
	};

	static int currentLevel;

	static void Start();
};
