#include "..\Public\COGBattery.h"
#include "Game\Public\COGMissile.h"

std::vector<COGBattery*> COGBattery::mBatComponents;

void COGBattery::ListenForCharge()
{
	if (Input::Instance()->IsKeyPressed(mShootInput))
	{
		if (mMissiles.size() > 0)
		{
		}
	}
}

void COGBattery::Initialize()
{
	AddToComponentVector(mBatComponents);
}


void COGBattery::Destroy()
{
	RemoveFromComponentVector(mBatComponents);
}

void COGBattery::SetControl(BatteryControl pControl)
{
	switch (pControl)
	{
	case BatteryControl::ONE:
		mShootInput = KeyCode::Alpha1;
		break;
	case BatteryControl::TWO:
		mShootInput = KeyCode::Alpha2;
		break;
	case BatteryControl::THREE:
		mShootInput = KeyCode::Alpha3;
		break;
	default:
		break;
	}
}
