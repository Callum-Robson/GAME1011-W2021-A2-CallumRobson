#pragma once
#include <string>
#include "GameObject.h"
#include "ButtonColours.h"
using namespace std;

class PuzzleButton final : public GameObject
{
public:
	PuzzleButton()
	{
		m_colour = NO_COLOUR;
		m_isPressed = false;
	}
	ButtonColour getColour()
	{
		return m_colour;
	}
	bool getIsPressed()
	{
		return m_isPressed;
	}
	void setButtonColour(ButtonColour colour)
	{
		m_colour = colour;
	}
	void setIsPressed(bool state)
	{
		m_isPressed = state;
	}
private:
	ButtonColour m_colour;
	bool m_isPressed;
};