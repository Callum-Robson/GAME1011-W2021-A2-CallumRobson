#include "Player.h"
#include "ListNode.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


int main()
{
	// building map
	GameObject* sword;
	sword = new GameObject();
	GameObject* key1;
	key1 = new GameObject();
	
	Chest* chest1;
	chest1 = new Chest();
	Door* door1;
	door1 = new Door();

	ListNode* room4 = new ListNode();
	
	ListNode* room3 = new ListNode();
	
	ListNode* room2 = new ListNode();
 
	ListNode* room1 = new ListNode(chest1, door1, room2);
	room1->chest->setPosition(WEST);
	room1->chest->setContents(sword);
	room1->chest->setContents(key1);
	room1->door->setPosition(NORTH);
	
	ListNode* head;
	head = new ListNode(room1);
	

	fstream inputFile;
	string currentDialogue;

	inputFile.open("Dialogue.txt");
	//Error checking
	if (inputFile.fail())
	{
		cout << "File open error!" << endl;
		return 1;
	}

	getline(inputFile, currentDialogue, '@'); // gets whole line instead of just up until " "(space) character
	
	//while (!inputFile.fail())	// could alternative be !file.eof()
	//{
		cout << currentDialogue << endl;
		/*file >> input;*/		// Reads next file data into input

		//getline(inputFile, currentDialogue);
	//}

		getline(inputFile, currentDialogue, '@');
		cout << currentDialogue << endl;

	
	inputFile.close();
	

	return 0;
}