#include "Player.h"
#include "TextureManager.h"

Player::Player()
{
	TextureManager::Instance()->load("../Assets/textures/circle.png", "circle");
	
	auto size = TextureManager::Instance()->getTextureSize("circle");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(400.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(PLAYER);
}

Player::~Player()
= default;

void Player::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	TextureManager::Instance()->draw("circle", x, y, 0, 255, true);
}

void Player::update()
{
	const float deltaTime = 1.0f / 60.f;

	glm::vec2 pos = getTransform()->position;
	pos.x += getRigidBody()->velocity.x * deltaTime;
	pos.y += getRigidBody()->velocity.y * deltaTime;

	getTransform()->position = pos;
}

void Player::clean()
{

}

void Player::moveLeft() {
	getRigidBody()->velocity = glm::vec2(-SPEED, 0.0f);
}

void Player::moveRight() {
	getRigidBody()->velocity = glm::vec2(SPEED, 0.0f);
}


//Lab 1 - 15th September-------------
void Player::moveUp()
{
	getRigidBody()->velocity = glm::vec2(0.0f, -SPEED);
}

void Player::moveDown()
{
	getRigidBody()->velocity = glm::vec2(0.0f, SPEED);
}

void Player::stopMoving()
{
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
}

float Player::checkDistance(GameObject* pGameObject) {
	
	//Lab 1 - 15th September-------------
	float enemyX = pGameObject->getTransform()->position.x;
	float enemyY = pGameObject->getTransform()->position.y;

	float x = enemyX - getTransform()->position.x;
	float y = enemyY - getTransform()->position.y;

	//pythogoras theorem = sqr_root(x^2 + x^2)
	return (sqrt(x*x + y*y));
}


//Lab 1 - 15th September-------------
bool Player::checkCollision(GameObject* pGameObject)
{
	if (checkDistance(pGameObject) < ((getWidth()*0.5) + (pGameObject->getWidth()*0.5)))
	{
		return true;
	}
	else
	{
		return false;
	}
}