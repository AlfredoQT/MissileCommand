#include "..\Public\World.h"
#include "..\Public\GameObject.h"
#include "Game\Public\GameObjectHandle.h"
#include "Game\Public\COGPhysics.h"

World::World(exEngineInterface* pEngine)
{
	mEngine = pEngine;
}

void World::Initialize()
{
	for (GameObjectHandle handle : mHandles)
	{
		if (handle.IsValid())
		{
			handle.Get()->Initialize();
		}
	}
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

void World::Update(float fDeltaT)
{
	for (COGPhysics* physics : COGPhysics::mPhysicsComponents)
	{
		physics->Update();
	}
}

void World::Add(GameObjectHandle pHandle)
{
	mHandles.push_back(pHandle);
}

exEngineInterface * World::Engine() const
{
	return mEngine;
}
