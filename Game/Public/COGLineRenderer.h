#pragma once

#include "Component.h"
#include "Engine\Public\Core\Types\Color.h"
#include "Engine\Public\Core\Types\Vector2.h"
#include <vector>

class COGLineRenderer : public Component
{
public:

	static std::vector<COGLineRenderer*> mLRComponents;

	virtual void Initialize() override;
	virtual void Destroy() override;

	void Draw() const;

	void SetColor(const Color& pColor);

private:

	std::vector<Vector2> mPoints;
	Color mColor;

};
