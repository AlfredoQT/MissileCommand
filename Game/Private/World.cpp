#include "..\Public\World.h"
#include "..\Public\GameObject.h"
#include "Game\Public\GameObjectHandle.h"
#include "Game\Public\COGPhysics.h"
#include "Engine\Public\Engine.h"
#include "Game\Public\COGLineRenderer.h"
#include "Game\Public\COGCollider.h"
#include "Game\Public\COGBattery.h"
#include "Game\Public\COGMissile.h"
#include "Game\Public\COGShape.h"
#include "Game\Public\COGGameManager.h"

World::World(Engine* pEngine)
{
	mEngine = pEngine;
	mGameManager = nullptr;
}

void World::Destroy()
{
	for (GameObjectHandle handle : mHandles)
	{
		if (handle.IsValid())
		{
			delete handle.Get();
		}
	}

	mHandles.clear();
}

void World::Update()
{
	for (COGPhysics* physics : COGPhysics::mPhysicsComponents)
	{
		physics->Update();
	}
	
	for (COGCollider* collider : COGCollider::mColliderComponents)
	{
		collider->CheckCollision();
	}

	for (COGLineRenderer* lines : COGLineRenderer::mLRComponents)
	{
		lines->Draw();
	}

	for (COGShape* shape : COGShape::mShapeComponents)
	{
		shape->Render();
	}

	for (COGMissile* missile : COGMissile::mMisComponents)
	{
		missile->Update();
	}

	for (COGBattery* bat : COGBattery::mBatComponents)
	{
		bat->ListenForCharge();
	}

	if (COGGameManager::mGameManagerComponent != nullptr)
	{
		mGameManager->Update();
	}
}

void World::Add(GameObjectHandle pHandle)
{
	mHandles.push_back(pHandle);
}

std::vector<GameObjectHandle> World::GetHandles()
{
	return mHandles;
}

Engine* World::GetEngine() const
{
	return mEngine;
}

void World::SetGameManager(COGGameManager * pGameManager)
{
	mGameManager = pGameManager;
}
