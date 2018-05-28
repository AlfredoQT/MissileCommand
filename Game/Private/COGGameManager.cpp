#include "..\Public\COGGameManager.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\GameObjectFactory.h"
#include "Game\Public\COGBattery.h"
#include "Game\Public\COGMissile.h"

COGGameManager* COGGameManager::mGameManagerComponent = nullptr;

COGGameManager::COGGameManager(GameObject * pGO)
	: Component(pGO)
{
	if (mGameManagerComponent != nullptr)
	{
		delete pGO;
	}
	else
	{
		mGameManagerComponent = this;
	}
}

void COGGameManager::Initialize()
{
}

void COGGameManager::Update()
{
}
