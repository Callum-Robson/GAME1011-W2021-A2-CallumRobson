#pragma once
#include "Positions.h"
#include "ObjectTypes.h"
#include <vector>

class GameObject
{
public:
	GameObject()
	{
		m_roomPosition = CENTER;
		m_objectType = NONE;
	}

	virtual ~GameObject()
		= default;

	Position getPosition() const
	{
		return m_roomPosition;
	}
	void setPosition(Position roomPosition)
	{
		m_roomPosition = roomPosition;
	}
	void setObjectType(ObjectType type)
	{
		m_objectType = type;
	}
	ObjectType getObjectType() const
	{
		return m_objectType;
	}

private:
	Position m_roomPosition;
	ObjectType m_objectType;
	
};