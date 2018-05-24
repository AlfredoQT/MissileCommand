#pragma once

#include "..\Public\Component.h"
#include <vector>

class World;

// our game object, it's just a collection of components - that's it!
class GameObject
{
public:
	
	GameObject(World* pWorld, std::size_t pHash);

	~GameObject();

	void Initialize();

	void AddComponent(Component* pComponent);

	template<class T>
	T* FindComponent(ComponentType eType)
	{
		for (Component* pComponent : mComponents)
		{
			if (pComponent->GetType() == eType)
			{
				return (T*)pComponent;
			}
		}

		return nullptr;
	}

	World* GetWorld() const;

	std::size_t GetHash();

private:
	std::vector<Component*> mComponents;

	World* mWorld;

	std::size_t mHash;

};
