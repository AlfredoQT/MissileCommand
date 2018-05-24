#pragma once

#include "Singleton.h"

class World;

class GameObjectFactory : public Singleton<GameObjectFactory>
{
public:

	GameObjectFactory();

	void CreateMissile(World* pWorld);

private:

	int mNextMissile;
	int mNextCity;
	int mNextExplosion;
};
