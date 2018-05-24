#include "..\Public\GameObjectInventory.h"
#include "Game\Public\GameObject.h"

void GameObjectInventory::Register(GameObject * pGO)
{
	mMap.Put(pGO->GetHash(), pGO);
}

void GameObjectInventory::UnRegister(GameObject * pGO)
{
	mMap.Remove(pGO->GetHash());
}

bool GameObjectInventory::Exists(GameObject * pGO)
{
	return mMap.Contains(pGO->GetHash());
}

GameObject* GameObjectInventory::Lookup(std::size_t pHash)
{
	return mMap.Get(pHash);
}
