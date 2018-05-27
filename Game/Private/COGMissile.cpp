#include "..\Public\COGMissile.h"
#include "Game\Public\COGLineRenderer.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\World.h"
#include "Engine\Public\Engine.h"
#include "Game\Public\COGPhysics.h"

std::vector<COGMissile*> COGMissile::mMisComponents;

COGMissile::COGMissile(GameObject * pGO)
	: Component(pGO)
{
}

void COGMissile::Initialize()
{
	mLR = mGO->FindComponent<COGLineRenderer>();
	mPhysics = mGO->FindComponent<COGPhysics>();
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
		DrawIdle();
	}
}

void COGMissile::Launch(const Vector2 & pTarget, const float& pSpeed)
{
	mLaunched = true;
	mTarget = pTarget;
	mSpeed = pSpeed;
}

void COGMissile::SetColor(const Color & pColor)
{
	mColor = pColor;
	mLR->SetColor(pColor);
}

bool COGMissile::Launched() const
{
	return mLaunched;
}

void COGMissile::DrawIdle()
{
}
