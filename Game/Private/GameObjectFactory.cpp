#include "..\Public\GameObjectFactory.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\World.h"
#include "Game\Public\GameObjectHandle.h"
#include "Game\Public\COGPhysics.h"
#include <string>

// Singleton
GameObjectFactory* Singleton<GameObjectFactory>::mSingleton = nullptr;

GameObjectFactory::GameObjectFactory()
	: mNextMissile(0)
	, mNextCity(0)
	, mNextExplosion(0)
{
}

void GameObjectFactory::CreateMissile(World* pWorld)
{
	GameObject* missile = new GameObject(pWorld, std::hash<std::string>{}("Missile-" + mNextMissile));
	missile->AddComponent(new COGPhysics(missile));

	pWorld->Add(missile->GetHandle());

	++mNextMissile;
}
