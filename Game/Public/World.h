#pragma once

#include "Game/Public/GameInterface.h"
#include <vector>

class GameObject;
class GameObjectHandle;

// the world, it contains all of our game objects and defines the order of updates
class World
{
public:

	World(exEngineInterface* pEngine);
	
	void Initialize();

	void Destroy();

	void Update(float fDeltaT);

	void Add(GameObjectHandle pHandle);

	exEngineInterface* Engine() const;

private:

	std::vector<GameObjectHandle> mHandles;

	exEngineInterface* mEngine;

};