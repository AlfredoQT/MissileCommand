#include "..\Public\COGMissile.h"
#include "Game\Public\COGLineRenderer.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\World.h"
#include "Engine\Public\Engine.h"

std::vector<COGMissile*> COGMissile::mMisComponents;

void COGMissile::Initialize()
{
	mLR = mGO->FindComponent<COGLineRenderer>();
	mTransform = mGO->FindComponent<COGTransform>();
	AddToComponentVector(mMisComponents);
	mLaunched = false;
}

void COGMissile::Destroy()
{
	RemoveFromComponentVector(mMisComponents);
}

void COGMissile::Update()
{
	if (!mLaunched)
	{
		
	}
}

void COGMissile::Launch(const Vector2 & pTarget)
{
	mLaunched = true;
	mTarget = pTarget;
}

void COGMissile::DrawIdle()
{
}
