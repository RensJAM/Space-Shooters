#include "Player.h"

	Player::Player()
		:	frameIndex(0),
			posX(50),
			posY(720 / 2.0f),
			shipTexture(LoadTexture("res/textures/spaceship-sprites.png"))
	{
	}

	Player::~Player()
	{
		UnloadTexture(shipTexture);
	}

	void Player::Draw() const
	{
		Rectangle source = { frameIndex * 40, 0, 40, 40 };
		Vector2 origin = { 20, 20 };
		float rotation = 90.0f;
		float scale = 2.0f;

		Rectangle dest = {
		posX + 20,
		posY - 20,
		40 * scale,
		40 * scale
		};

		DrawTexturePro(
			shipTexture,
			source,
			dest,
			origin,
			rotation,
			WHITE
		);
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
		bullets.push_back({ posX + 30.0f, posY - 5.0f, 1000.0f });
	}