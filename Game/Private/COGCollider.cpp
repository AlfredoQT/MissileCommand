#include "..\Public\COGCollider.h"
#include "Game\Public\World.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\GameObjectHandle.h"
#include "Game\Public\COGTransform.h"
#include "Engine\Public\Core\Types\Vector2.h"

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
			GameObject* gameObject = handles[i].Get();

			if (gameObject != mGO)
			{
				COGCollider* other = gameObject->FindComponent<COGCollider>();
				if (other != nullptr)
				{
					Vector2 toOther = gameObject->FindComponent<COGTransform>()->GetPosition() - mGO->FindComponent<COGTransform>()->GetPosition();
					bool colliding = toOther.SizeSquared() <= (mRadius + other->GetRadius()) * (mRadius + other->GetRadius());
					if (colliding)
					{
						// Activate OnCollision on all components
						std::vector<Component*> components = mGO->GetComponents();
						for (int i = 0; i < components.size(); ++i)
						{
							components[i]->OnCollision(other);
						}
					}
				}
			}
		}
	}
}

float COGCollider::GetRadius()
{
	return mRadius;
}

void COGCollider::SetRadius(const float & pRadius)
{
	mRadius = pRadius;
}
