#pragma once

#include "Component.h"
#include "Vector2.h"
#include <vector>

class GameObject;
class COGTransform;

class COGPhysics : public Component
{
public:

	static std::vector<COGPhysics*> mPhysicsComponents;

	COGPhysics(GameObject* pGO);

	virtual void Initialize() override;

	virtual void Destroy() override;

	void Update(float fDeltaT);

private:

	Vector2 mVelocity;

	COGTransform* mTransform;

};
