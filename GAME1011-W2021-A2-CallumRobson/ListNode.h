#pragma once
#include "Chest.h"
#include "Door.h"
#include "PuzzleButton.h"


struct ListNode
{
	Chest* chest= new Chest;
	Door* door = new Door;
	PuzzleButton* redButton = new PuzzleButton;
	PuzzleButton* blueButton = new PuzzleButton;
	PuzzleButton* greenButton = new PuzzleButton;
	ListNode* next;

	ListNode(ListNode* next1 = nullptr)
	{
		next = next1;
	}
	
};


struct puzzleNode
{
	bool actionCompleted;
	std::string action;
};