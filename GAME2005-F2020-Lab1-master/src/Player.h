#pragma once
#ifndef __PLAYER__
#define __PLAYER__

#include "Sprite.h"
#include "Label.h"

class Player final : public Sprite
{
public:
	Player();
	~Player();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	void moveLeft();
	void moveRight();
	float checkDistance(GameObject* pGameObject);

	
	//Lab 1 - 15th September-------------
	void moveUp();
	void moveDown();
	void stopMoving();


	//Lab 1 - 15th September-------------
	bool checkCollision(GameObject* pGameObject);

private:
	const float SPEED = 50.0f;
};

#endif /* defined (__PLAYER__) */