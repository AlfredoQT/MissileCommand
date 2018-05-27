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
	
	void Initialize();

	void Destroy();

	void Update();

	void Add(GameObjectHandle pHandle);

	Engine* GetEngine() const;

private:

	std::vector<GameObjectHandle> mHandles;

	Engine* mEngine;

};