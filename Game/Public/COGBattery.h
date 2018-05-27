#pragma once

#include "Component.h"
#include "Input.h"
#include <vector>

enum class BatteryControl : int
{
	ONE = 0,
	TWO,
	THREE
};

class COGMissile;

class COGBattery : public Component
{
public:

	static std::vector<COGBattery*> mBatComponents;

	virtual void Initialize() override;
	virtual void Destroy() override;

	std::vector<COGMissile*> mMissiles;

	void ListenForCharge();

	void SetControl(BatteryControl pControl);

private:

	KeyCode mShootInput;

};
