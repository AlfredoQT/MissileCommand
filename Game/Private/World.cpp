#include "..\Public\World.h"
#include "..\Public\GameObject.h"
#include "Game\Public\GameObjectHandle.h"
#include "Game\Public\COGPhysics.h"
#include "Engine\Public\Engine.h"
#include "Game\Public\COGLineRenderer.h"
#include "Game\Public\COGBattery.h"

World::World(Engine* pEngine)
{
	mEngine = pEngine;
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

	for (COGLineRenderer* lines : COGLineRenderer::mLRComponents)
	{
		lines->Draw();
	}

	for (COGBattery* bat : COGBattery::mBatComponents)
	{
		bat->ListenForCharge();
	}
}

void World::Add(GameObjectHandle pHandle)
{
	mHandles.push_back(pHandle);
}

Engine* World::GetEngine() const
{
	return mEngine;
}
