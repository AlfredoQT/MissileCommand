#include "..\Public\COGCollider.h"
#include "Game\Public\World.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\GameObjectHandle.h"

std::vector<COGCollider*> COGCollider::mColliderComponents;

COGCollider::COGCollider(GameObject * pGO)
	: Component(pGO)
{
}

void COGCollider::Initialize()
{
	AddToComponentVector(mColliderComponents);
}

void COGCollider::Destroy()
{
	RemoveFromComponentVector(mColliderComponents);
}

void COGCollider::CheckCollision()
{
	std::vector<GameObjectHandle> handles = mGO->GetWorld()->GetHandles();
	// Look at all the handles in the world
	for (int i = 0; i < handles.size(); ++i)
	{
		if (handles[i].IsValid())
		{
			COGCollider* other = handles[i].Get()->FindComponent<COGCollider>();
			if (other == nullptr)
			{

			}
		}
	}
}
