#pragma once
#include "GameObject.h"

class Player final : public GameObject
{
public:
	Player()
	{
		setObjectType(PLAYER);
	}

	void setInventory(GameObject* item)
	{
		if (m_inventory.size() < 20)
			m_inventory.push_back(item);
	}
	GameObject* getInventoryItem(int position)
	{
		return m_inventory[position];
	}
private:
	std::vector<GameObject*> m_inventory;
};
