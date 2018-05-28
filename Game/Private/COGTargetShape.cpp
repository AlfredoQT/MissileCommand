#include "..\Public\COGTargetShape.h"
#include "Game\Public\COGTransform.h"
#include "Game\Public\World.h"
#include "Game\Public\GameObject.h"
#include "Engine\Public\Engine.h"
#include "Game\Public\Random.h"
#include "Engine\Public\Core\Types\Color.h"

COGTargetShape::COGTargetShape(GameObject * pGO)
	: COGShape(pGO)
{
}

void COGTargetShape::Render()
{
	Color randomColor = Color(Random::Instance()->NextInt(100, 255), Random::Instance()->NextInt(100, 255), Random::Instance()->NextInt(0, 255));
	mGO->GetWorld()->GetEngine()->DrawLine(Vector2(mTrans->GetPosition().x - 7, mTrans->GetPosition().y - 7), Vector2(mTrans->GetPosition().x + 7, mTrans->GetPosition().y + 7), randomColor);
	mGO->GetWorld()->GetEngine()->DrawLine(Vector2(mTrans->GetPosition().x + 7, mTrans->GetPosition().y - 7), Vector2(mTrans->GetPosition().x - 7, mTrans->GetPosition().y + 7), randomColor);
}


