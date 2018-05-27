#include "..\Public\COGPhysics.h"
#include "Game\Public\COGTransform.h"
#include "Game\Public\GameObject.h"
#include "Engine\Public\Core\Time.h"

std::vector<COGPhysics*> COGPhysics::mPhysicsComponents;

COGPhysics::COGPhysics(GameObject * pGO)
	: Component(pGO)
{
}

void COGPhysics::Initialize()
{
	mTransform = mGO->FindComponent<COGTransform>();
	AddToComponentVector(mPhysicsComponents);
}

void COGPhysics::Destroy()
{
	RemoveFromComponentVector(mPhysicsComponents);
}

void COGPhysics::Update()
{
	// Update position
	Vector2 currentPosition = mTransform->GetPosition();
	Vector2 newPosition = currentPosition + mVelocity * Time::deltaTime;
	mTransform->SetPosition(newPosition);
}
