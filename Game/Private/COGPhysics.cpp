#include "..\Public\COGPhysics.h"
#include "Game\Public\Debug.h"

std::vector<COGPhysics*> COGPhysics::mPhysicsComponents;

COGPhysics::COGPhysics(GameObject * pGO)
	: Component(pGO)
{
}

ComponentType COGPhysics::GetType() const
{
	return ComponentType::Physics;
}

void COGPhysics::Initialize()
{
	AddToComponentVector(mPhysicsComponents);
}

void COGPhysics::Destroy()
{
	RemoveFromComponentVector(mPhysicsComponents);
}

void COGPhysics::Update()
{
	Debug::exOutputLine(108);
}
