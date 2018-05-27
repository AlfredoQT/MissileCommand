#include "..\Public\MissileCommandGame.h"
#include "Engine\Public\Core\Time.h"
#include "Engine\Public\Engine.h"
#include "Game\Public\InputManager.h"
#include "Game\Public\World.h"

MissileCommandGame::MissileCommandGame()
	: mWorld(nullptr)
{
}

void MissileCommandGame::Init(Engine* pEngine)
{
	mWorld = new World(pEngine);
}

void MissileCommandGame::Run()
{
	InputManager::Instance()->Update();

	mWorld->Update();

	InputManager::Instance()->LateUpdate();
}

void MissileCommandGame::End()
{
	mWorld->Destroy();
}
