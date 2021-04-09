#include "Player.h"
#include "ListNode.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


int main()
{
	bool gameIsRunning = true;
	Player thePlayer;
	string playerChoice;
//Game objects
	GameObject* sword = new GameObject();
	sword->setObjectType(SWORD);
	GameObject* key1 = new GameObject();
	key1->setObjectType(KEY);
	Chest* chest1 = new Chest();
	Door* door1 = new Door();
//Rooms
	ListNode* room4 = new ListNode();
	ListNode* room3 = new ListNode();
	ListNode* room2 = new ListNode();
	room2->door->setPosition(NORTH);
	room2->button1->setButtonColour(RED);
	room2->button2->setButtonColour(BLUE);
	room2->button3->setButtonColour(GREEN);
	room2->button1->setPosition(WEST);
	room2->button2->setPosition(CENTER);
	room2->button3->setPosition(EAST);
	
	ListNode* room1 = new ListNode(chest1, door1, room2);
	room1->door->setPosition(NORTH);
	room1->chest->setPosition(WEST);
	room1->chest->setContents(sword);
	room1->chest->setContents(key1);

	ListNode* head = new ListNode(room1);

//Text file stuff
	fstream inputFile;
	string currentDialogue;
	inputFile.open("Dialogue.txt");
	//Error checking
		if (inputFile.fail())
		{
			cout << "File open error!" << endl;
			return 1;
		}

////////////////////

///////Game/////////

////////////////////
///
		getline(inputFile, currentDialogue, '@');

		cout << currentDialogue << endl;
	
		while (gameIsRunning == true)
		{
			cin >> playerChoice;


			if (playerChoice == "NORTH")
			{
				thePlayer.setPosition(NORTH);
			}
			if (playerChoice == "EAST")
			{
				thePlayer.setPosition(EAST);
			}
			if (playerChoice == "SOUTH")
			{
				thePlayer.setPosition(SOUTH);
			}
			if (playerChoice == "WEST")
			{
				thePlayer.setPosition(WEST);
			}
			if (playerChoice == "CENTER")
			{
				thePlayer.setPosition(CENTER);
			}


			if (thePlayer.getCurrentRoom() == 1)
			{


				if (thePlayer.getPosition() == room1->door->getPosition())
				{
					if (thePlayer.getHasKey() == true)
					{
						inputFile.seekg(304L, ios::beg);
						getline(inputFile, currentDialogue, '@');
						cout << currentDialogue << endl;
						thePlayer.setCurrentRoom(2);
					}
					else
					{
						inputFile.seekg(220L, ios::beg);
						getline(inputFile, currentDialogue, '@');
						cout << currentDialogue << endl;
					}
				}
				else if (thePlayer.getPosition() == room1->chest->getPosition())
				{
					if (chest1->getHasBeenLooted() == false)
					{
						inputFile.seekg(134L, ios::beg);
						getline(inputFile, currentDialogue, '@');
						cout << currentDialogue << endl;
						for (int j = 0; j < 2; j++)
						{
							thePlayer.setInventory(chest1->getContents(j));
						}
						chest1->setHasBeenLooted(true);
					}
					else
					{
						inputFile.seekg(653L, ios::beg);
						getline(inputFile, currentDialogue, '@');
						cout << currentDialogue << endl;
					}
				}
				else
				{
					inputFile.seekg(727L, ios::beg);
					getline(inputFile, currentDialogue, '@');
					cout << currentDialogue << endl;
				}
				for (int i = 0; i < thePlayer.getInventorySize(); i++)
				{
					if (thePlayer.getInventoryItem(i)->getObjectType() == KEY)
						thePlayer.setHasKey(true);
				}
				
			}
			else if (thePlayer.getCurrentRoom() == 2)
			{
				if (thePlayer.getPosition() == room2->door->getPosition())
				{
					if (room2->door->getIsLocked() == false)
					{
						inputFile.seekg(304L, ios::beg);
						getline(inputFile, currentDialogue, '@');
						cout << currentDialogue << endl;
						thePlayer.setCurrentRoom(2);
					}
					else
					{
						inputFile.seekg(220L, ios::beg);
						getline(inputFile, currentDialogue, '@');
						cout << currentDialogue << endl;
					}
				}

			}

		}
	
	inputFile.close();

	return 0;
}