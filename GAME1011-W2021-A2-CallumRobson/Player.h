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
		setInventorySize();
	}
	void setInventorySize()
	{
		inventorySize = m_inventory.size();
	}
	void setHasKey(bool state)
	{
		hasKey = state;
	}
	void setCurrentRoom(int room)
	{
		currentRoom = room;
	}
	GameObject* getInventoryItem(int position)
	{
		return m_inventory[position];
	}
	int getInventorySize() const
	{
		return inventorySize;
	}
	bool getHasKey() const
	{
		return hasKey;
	}
	int getCurrentRoom() const
	{
		return currentRoom;
	}
private:
	std::vector<GameObject*> m_inventory;
	int inventorySize;
	bool hasKey = false;
	int currentRoom = 1;
};
