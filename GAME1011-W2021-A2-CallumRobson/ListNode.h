#pragma once
#include "Chest.h"
#include "Door.h"
#include "PuzzleButton.h"


struct ListNode
{
	Chest* chest = new Chest;
	Door* door = new Door;
	PuzzleButton* button1 = new PuzzleButton;
	PuzzleButton* button2 = new PuzzleButton;
	PuzzleButton* button3 = new PuzzleButton;
	ListNode* next;

	ListNode(ListNode* next1 = nullptr)
	{
		next = next1;
	}
	
	ListNode(Chest* chest1, Door* door1, ListNode* next1 = nullptr)
	{
		chest = chest1;
		door = door1;
		next = next1;
	}
};