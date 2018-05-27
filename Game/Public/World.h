#pragma once
#include <vector>

class GameObject;
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

private:

	std::vector<GameObjectHandle> mHandles;

	Engine* mEngine;

};