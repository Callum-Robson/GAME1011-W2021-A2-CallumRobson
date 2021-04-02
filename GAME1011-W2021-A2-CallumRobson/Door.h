#pragma once
#include "GameObject.h"

class Door final : public GameObject
{
public:
	Door()
	{
		m_isLocked = false;
	}
	~Door()
		= default;
	void setIsLocked(bool state)
	{
		m_isLocked = state;
	}
private:
	bool m_isLocked;
};