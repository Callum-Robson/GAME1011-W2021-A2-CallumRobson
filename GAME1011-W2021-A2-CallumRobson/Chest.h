#pragma once
#include "GameObject.h"

class Chest final : public GameObject
{
public:
	Chest()
	{
		setObjectType(CHEST);
	}
	~Chest() override = default;

	void setContents(GameObject* item)
	{
		if (m_contents.size() < 3)
		{
			m_contents.push_back(item);
		}
	}
	std::vector<GameObject*> getContents() const
	{
		return m_contents;
	}

private:
	std::vector<GameObject*> m_contents;
};