#include "Player.h"


	Player::Player()
	{
		Player::posX = 50;
		Player::posY = 720 / 2.0f;
	}

	Player::~Player()
	{
	}

	void Player::Draw() const
	{
		DrawRectangle(posX - 20, posY - 20, 40, 40, BLUE);
	}

	void Player::MoveUp()
	{
		if (posY > (720 / 7.0f))
			posY -= (720 / 7.0f);
	}

	void Player::MoveDown()
	{
		if (posY < (720 / 7 * 6))
			posY += (720 / 7.0f);
	}

	void Player::Shoot() const
	{
		bullets.push_back({ posX + 30.0f, posY - 5.0f, 500.0f });
	}