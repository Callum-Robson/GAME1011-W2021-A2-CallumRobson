#pragma once
#include "GameObject.h"

class Door final : public GameObject
{
public:
	Door()
	{
		m_isLocked = true;
		setObjectType(DOOR);
	}
	~Door()
		= default;
	void setIsLocked(bool state)
	{
		m_isLocked = state;
	}
	bool getIsLocked()
	{
		return m_isLocked;
	}
private:
	bool m_isLocked;
};