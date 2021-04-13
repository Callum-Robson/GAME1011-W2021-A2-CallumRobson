#pragma once
#include "Chest.h"
#include "Door.h"
#include "PuzzleButton.h"

class RoomList
{
public:
	struct RoomNode
	{
		Chest* chest = new Chest;
		Door* door = new Door;
		PuzzleButton* redButton = new PuzzleButton;
		PuzzleButton* blueButton = new PuzzleButton;
		PuzzleButton* greenButton = new PuzzleButton;
		RoomNode* next;
		RoomNode(RoomNode* room = nullptr)
		{
			next = room;
		}
	};

	RoomNode* head;
public:
	RoomList() { head = nullptr; }
	~RoomList();
	void add(RoomNode* room);
	void remove(RoomNode*);
	void displayList() const;
};