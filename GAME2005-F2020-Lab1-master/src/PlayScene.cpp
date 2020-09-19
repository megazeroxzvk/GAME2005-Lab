#include "PlayScene.h"
#include "Game.h"
#include "EventManager.h"

PlayScene::PlayScene()
{
	PlayScene::start();
}

PlayScene::~PlayScene()
= default;

void PlayScene::draw()
{
	drawDisplayList();
}

void PlayScene::update()
{
	updateDisplayList();

	//Lab 1 - 15th September-------------
	constantDistanceCheck();
	
}

void PlayScene::clean()
{
	removeAllChildren();
}

void PlayScene::handleEvents()
{
	EventManager::Instance().update();

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_A))
	{
		m_pPlayer->moveLeft();
	}
	else if (EventManager::Instance().isKeyDown(SDL_SCANCODE_D))
	{
		m_pPlayer->moveRight();
	}
	else if (EventManager::Instance().isKeyDown(SDL_SCANCODE_W))		//Lab 1 - 15th September-------------
	{
		//Move Upwards
		m_pPlayer->moveUp();
	}
	else if (EventManager::Instance().isKeyDown(SDL_SCANCODE_S))
	{
		//Move Downwards
		m_pPlayer->moveDown();
	}
	else
	{
		//Stop Movement
		m_pPlayer->stopMoving();
	}
	//Note: cannot move diagonally using two keys.
	
	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

}

void PlayScene::start()
{
	// Player Sprite
	m_pPlayer = new Player();
	addChild(m_pPlayer);
	
	// Enemy Sprite
	m_pEnemy = new Enemy();
	addChild(m_pEnemy);

	// Label
	const SDL_Color blue = { 0, 0, 255, 255 };
	m_pDistanceLabel = new Label("Distance", "Consolas", 40, blue, glm::vec2(400.0f, 40.0f));
	m_pDistanceLabel->setParent(this);
	addChild(m_pDistanceLabel);
}

//Lab 1 - 15th September-------------
void PlayScene::constantDistanceCheck()
{
	float distance = m_pPlayer->checkDistance(m_pEnemy);
	if (m_pPlayer->checkCollision(m_pEnemy))
	{
		std::string hit = "HIT!";
		m_pDistanceLabel->setText("Distance = " + hit);
	}
	else
	{
		m_pDistanceLabel->setText("Distance = " + std::to_string(distance));
	}
}
