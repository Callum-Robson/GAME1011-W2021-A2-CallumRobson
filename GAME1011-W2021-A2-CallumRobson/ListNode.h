#pragma once
#include "Chest.h"
#include "Door.h"


struct ListNode
{
	Chest chest;
	Door door;
	ListNode* next;

	ListNode(ListNode* next1 = nullptr)
	{
		next = next1;
	}
	
	ListNode(Chest chest1, Door door1, ListNode* next1 = nullptr)
	{
		chest = chest1;
		door = door1;
		next = next1;
	}
};