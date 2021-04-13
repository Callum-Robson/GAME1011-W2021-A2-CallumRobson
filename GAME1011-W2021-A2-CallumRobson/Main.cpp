#include "Player.h"
#include "ListNode.h"
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <forward_list>
#include "ButtonColours.h"
using namespace std;


int main()
{
	bool gameIsRunning = true;
	Player thePlayer;
	string playerChoice;
	
	forward_list<PuzzleButton*> buttonOrder;
	ButtonColour correctOrder[3] = { BLUE, RED, GREEN };
	int buttonsPressed = 0;
	
	
//Game objects
	GameObject* sword = new GameObject();
	sword->setObjectType(SWORD);
	GameObject* key1 = new GameObject();
	key1->setObjectType(KEY);
	
//Rooms
	ListNode* room4 = new ListNode();
	
	ListNode* room3 = new ListNode(room4);
	
	ListNode* room2 = new ListNode(room3);
	room2->door->setPosition(NORTH);
	room2->redButton->setButtonColour(RED);
	room2->blueButton->setButtonColour(BLUE);
	room2->greenButton->setButtonColour(GREEN);
	room2->redButton->setPosition(WEST);
	room2->blueButton->setPosition(EAST);
	room2->greenButton->setPosition(CENTER);
	
	ListNode* room1 = new ListNode(room2);
	room1->door->setPosition(NORTH);
	room1->chest->setPosition(WEST);
	room1->chest->setContents(sword);
	room1->chest->setContents(key1);

	ListNode* head = new ListNode(room1);

	//Text file stuff
	fstream inputFile;
	string currentDialogue;
	inputFile.open("Dialogue.txt");
	
	if (inputFile.fail())
	{
		cout << "File open error!" << endl;
		return 1;
	}

	////////////////////
	///////Game/////////
	////////////////////

		getline(inputFile, currentDialogue, '@');

		cout << currentDialogue << endl;
	
		while (gameIsRunning == true)
		{
				
			playerChoice = "blank";
			while (playerChoice != "NORTH" && playerChoice != "EAST"
				&& playerChoice != "SOUTH" && playerChoice != "WEST" && playerChoice != "CENTER")
			{
				cin >> playerChoice;
				std::transform(playerChoice.begin(), playerChoice.end(), playerChoice.begin(), ::toupper);
				if (playerChoice != "NORTH" && playerChoice != "EAST"
					&& playerChoice != "SOUTH" && playerChoice != "WEST" && playerChoice != "CENTER")
				{
					std::cout << "Enter one of the following directions: North, East, West, South, Center\n";
				}
			}

			if (playerChoice == "NORTH")
			{
				thePlayer.setPosition(NORTH);
			}
			else if (playerChoice == "EAST")
			{
				thePlayer.setPosition(EAST);
			}
			else if (playerChoice == "SOUTH")
			{
				thePlayer.setPosition(SOUTH);
			}
			else if (playerChoice == "WEST")
			{
				thePlayer.setPosition(WEST);
			}
			else if (playerChoice == "CENTER")
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
					if (room1->chest->getHasBeenLooted() == false)
					{
						inputFile.seekg(134L, ios::beg);
						getline(inputFile, currentDialogue, '@');
						cout << currentDialogue << endl;
						for (int j = 0; j < 2; j++)
						{
							thePlayer.setInventory(room1->chest->getContents(j));
						}
						room1->chest->setHasBeenLooted(true);
					}
					else
					{
						inputFile.seekg(667L, ios::beg);
						getline(inputFile, currentDialogue, '@');
						cout << currentDialogue << endl;
					}
				}
				else
				{
					inputFile.seekg(741L, ios::beg);
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
						inputFile.seekg(815L, ios::beg);
						getline(inputFile, currentDialogue, '@');
						cout << currentDialogue << endl;
						thePlayer.setCurrentRoom(3);
					}
					else
					{
						inputFile.seekg(1190L, ios::beg);
						getline(inputFile, currentDialogue, '@');
						cout << currentDialogue << endl;
					}
				}
				else if (thePlayer.getPosition() == room2->redButton->getPosition())
				{
					if(room2->redButton->getIsPressed() == false)
					{
						inputFile.seekg(1254, ios::beg);
						getline(inputFile, currentDialogue, '@');
						cout << currentDialogue << endl;
						room2->redButton->setIsPressed(true);
						buttonOrder.push_front(room2->redButton);
						buttonsPressed++;
					}
					else
					{
						inputFile.seekg(1533, ios::beg);
						getline(inputFile, currentDialogue, '@');
						cout << currentDialogue << endl;
					}
				}
				else if (thePlayer.getPosition() == room2->greenButton->getPosition())
				{
					if (room2->greenButton->getIsPressed() == false)
					{
						inputFile.seekg(1439, ios::beg);
						getline(inputFile, currentDialogue, '@');
						cout << currentDialogue << endl;
						room2->greenButton->setIsPressed(true);
						buttonOrder.push_front(room2->greenButton);
						buttonsPressed++;
					}
					else
					{
						inputFile.seekg(1533, ios::beg);
						getline(inputFile, currentDialogue, '@');
						cout << currentDialogue << endl;
					}
				}
				else if (thePlayer.getPosition() == room2->blueButton->getPosition())
				{
					if (room2->blueButton->getIsPressed() == false)
					{
						inputFile.seekg(1346, ios::beg);
						getline(inputFile, currentDialogue, '@');
						cout << currentDialogue << endl;
						room2->blueButton->setIsPressed(true);
						buttonOrder.push_front(room2->blueButton);
						buttonsPressed++;
					}
					else
					{
						inputFile.seekg(1533, ios::beg);
						getline(inputFile, currentDialogue, '@');
						cout << currentDialogue << endl;
					}
				}
				else
				{
					inputFile.seekg(741L, ios::beg);
					getline(inputFile, currentDialogue, '@');
					cout << currentDialogue << endl;
				}
				if (buttonsPressed == 3)
				{
					if (static_cast<PuzzleButton*>(buttonOrder.front())->getColour() == correctOrder[2])
					{
						buttonOrder.pop_front();
						if (static_cast<PuzzleButton*>(buttonOrder.front())->getColour() == correctOrder[1])
						{
							buttonOrder.pop_front();
							if (static_cast<PuzzleButton*>(buttonOrder.front())->getColour() == correctOrder[0])
							{
								room2->door->setIsLocked(false);
								inputFile.seekg(1689, ios::beg);
								getline(inputFile, currentDialogue, '@');
								cout << currentDialogue << endl;
							}
						}
					}
					buttonsPressed = 0;
					buttonOrder.clear();
					if (room2->door->getIsLocked() == true)
					{
						inputFile.seekg(1605, ios::beg);
						getline(inputFile, currentDialogue, '@');
						cout << currentDialogue << endl;
						room2->blueButton->setIsPressed(false);
						room2->greenButton->setIsPressed(false);
						room2->redButton->setIsPressed(false);
					}
				}
				
			}
			else if (thePlayer.getCurrentRoom() == 3)
			{
				if(thePlayer.getPosition() == CENTER || thePlayer.getPosition() == NORTH)
				{
					inputFile.seekg(1797, ios::beg);
					getline(inputFile, currentDialogue, '@');
					cout << currentDialogue << endl;
					gameIsRunning = false;
				}
				else if (thePlayer.getPosition() == WEST)
				{
					inputFile.seekg(1881, ios::beg);
					getline(inputFile, currentDialogue, '@');
					cout << currentDialogue << endl;
					gameIsRunning = false;
				}
				else
				{
					inputFile.seekg(741L, ios::beg);
					getline(inputFile, currentDialogue, '@');
					cout << currentDialogue << endl;
				}
				
			}
		}
	
	inputFile.close();

	return 0;
}