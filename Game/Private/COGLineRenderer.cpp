#include "..\Public\COGLineRenderer.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\World.h"
#include "Engine\Public\Engine.h"

std::vector<COGLineRenderer*> COGLineRenderer::mLRComponents;

COGLineRenderer::COGLineRenderer(GameObject * pGO)
	: Component(pGO)
{
}

void COGLineRenderer::Initialize()
{
	AddToComponentVector(mLRComponents);
}


void COGLineRenderer::Destroy()
{
	RemoveFromComponentVector(mLRComponents);
}

void COGLineRenderer::Draw() const
{
	// Draw every line
	for (int i = 0; i < mPoints.size() - 1; ++i)
	{
		mGO->GetWorld()->GetEngine()->DrawLine(mPoints[i], mPoints[i + 1], mColor);
	}
}

void COGLineRenderer::SetColor(const Color & pColor)
{
	mColor = pColor;
}

void COGLineRenderer::AddPoint(const Vector2 & pPoint)
{
	mPoints.push_back(pPoint);
}

void COGLineRenderer::SetPoint(int pIndex, const Vector2 & pPoint)
{
	Vector2& point = mPoints.at(pIndex);
	point = pPoint;
}

std::vector<Vector2> COGLineRenderer::GetPoints()
{
	return mPoints;
}
