#pragma once

#include "Game\Public\Component.h"
#include <vector>

class GameObject;

class COGPhysics : public Component
{
public:

	static std::vector<COGPhysics*> mPhysicsComponents;

	COGPhysics(GameObject* pGO);

	virtual ComponentType GetType() const override;

	virtual void Initialize() override;

	virtual void Destroy() override;

	void Update();

};
