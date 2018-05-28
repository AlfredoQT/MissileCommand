#pragma once
#include <vector>

class COGGameManager;
class GameObjectHandle;
class Engine;

// the world, it contains all of our game objects and defines the order of updates
class World
{
public:

	World(Engine* pEngine);

	void Destroy();

	void Update();

	void Add(GameObjectHandle pHandle);

	std::vector<GameObjectHandle> GetHandles();

	Engine* GetEngine() const;

	void SetGameManager(COGGameManager* pGameManager);

private:

	std::vector<GameObjectHandle> mHandles;

	Engine* mEngine;

	COGGameManager* mGameManager;

};