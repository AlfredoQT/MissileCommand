#pragma once

#include "Component.h"
#include "Engine\Public\Core\Types\Vector2.h"
#include "Engine\Public\Core\Types\Color.h"
#include <vector>

class COGLineRenderer;
class COGTransform;

class COGMissile : public Component
{
public:

	static std::vector<COGMissile*> mMisComponents;

	virtual void Initialize() override;
	virtual void Destroy() override;

	void Update();

	void Launch(const Vector2& pTarget);

private:

	void DrawIdle();

	COGLineRenderer * mLR;

	COGTransform* mTransform;

	bool mLaunched;

	Vector2 mTarget;

	Color mColor;

};
