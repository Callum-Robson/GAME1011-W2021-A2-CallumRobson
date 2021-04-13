#pragma once
#include "GameObject.h"

class Chest final : public GameObject
{
public:
	Chest()
	{
		setObjectType(CHEST);
		m_hasBeenLooted = false;
	}
	~Chest() override = default;

	void setContents(GameObject* item)
	{
		if (m_contents.size() < 2)
		{
			m_contents.push_back(item);
		}
	}
	GameObject* getContents(int position) const
	{
			return m_contents[position];
	}
	void setHasBeenLooted(bool state)
	{
		m_hasBeenLooted = state;
	}
	bool getHasBeenLooted()
	{
		return m_hasBeenLooted;
	}

private:
	std::vector<GameObject*> m_contents;
	bool m_hasBeenLooted;
};