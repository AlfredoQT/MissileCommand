#pragma once

#include "Component.h"

class GameObject;

class COGGameManager : public Component
{
public:

	COGGameManager(GameObject* pGO);

	virtual void Initialize() override;

};
	