#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;
string playerName;
string playerInput;
bool startRoom = false;
bool hallway = false;
bool hasLook = false;
bool isStanding = false;
bool hasKeys = false;

// Color References
// 0C = Red on Black,  0F = White on Black
void beginning();
void goSleep();
void getKeys();
void getDoor();
void standUp();

//FUNCTION FOR WINNING THE GAME
void winnable()
{
	cout << "But that doesn't matter cause you already left." << endl;
	cout << "You escaped!" << endl;
	system("Pause");
	cout << "\n\n\n";
	cout << "Thanks for playing my game!" << endl;
	cout << "Would you like to play again? [y/n]" << endl;

	cin >> playerInput;

	//WILL THE PLAYER PLAY THE GAME AGAIN
	if (playerInput == "y" || playerInput == "Y" || playerInput == "yes" || playerInput == "Yes") {
		cout << "\n\n\n";
		beginning();
	}
	if (playerInput == "n" || playerInput == "N" || playerInput == "no" || playerInput == "No") {
		return;
	}

	beginning();
}

//FUNCTION FOR THE PLAYER DYING
void dead() {
	system("Color 0C");
	string deadboi = "You died.";
	int x = 0;
	while (deadboi[x] != '\0')
	{
		cout << deadboi[x];
		Sleep(150);
		x++;
	};
	system("Color 0F");

	//FUNCTIONS ARE NOW RESET
	startRoom = false;
	hallway = false;
	hasLook = false;
	isStanding = false;
	system("Pause");
	cout << "\n\n\n";
	system("Color 0F");
	cout << "Thanks for playing!" << endl;
	cout << "Would you like to play again?  [y/n]" << endl;
	cin >> playerInput;

	if (playerInput == "y" || playerInput == "Y" || playerInput == "yes" || playerInput == "Yes") {
		cout << "\n\n\n";
		beginning();
	}
	if (playerInput == "n" || playerInput == "N" || playerInput == "no" || playerInput == "No") {
		return;
	}

	beginning();
}

//FUNCTION FOR THE PLAYER GOING TO SLEEP
void goSleep() {
	cout << "\n\n";
	cout << "You lay in the fetal position until you drift off into slumber." << endl;
	cout << "If you don't know where you are, why would you sleep?" << endl;
	system("Pause");
	cout << "\n\n\n";
	dead();
}

//FUNCTION FOR THE PLAYER OBTAINING THE KEYS
void getKeys() {
	//IF THE PLAYER ISN'T STANDING UP YET
	if (isStanding == false) {
		cout << "You may want to get up off the floor first." << endl;
		cout << "\n\n\n";
		cout << "Actions: Stand, Door, Sleep" << endl;
		cin >> playerInput;
		cout << "\n\n\n";

		if (playerInput == "stand" || playerInput == "Stand") {
			standUp();
		}
		if (playerInput == "door" || playerInput == "Door") {
			getDoor();
		}
		if (playerInput == "sleep" || playerInput == "Sleep") {
			goSleep();
		}
		else
		{
			dead();
		}
	}
	//IF THE PLAYER IS ALREADY STANDING
	if (isStanding == true) {
		hasKeys = true;
		cout << "You take the keys, shoving them into your coat pocket." << endl;
		cout << "The familiar action gives you comfort." << endl;
		cout << "\n\n\n";
		cout << "Actions: Door, Sleep" << endl;
		cin >> playerInput;

		if (playerInput == "door" || playerInput == "Door") {
			getDoor();
		}
		if (playerInput == "sleep" || playerInput == "Sleep") {
			goSleep();
		}
		else {
			dead();
		}
	}
}

//FUNCTION FOR THE PLAYER GOING THROUGH THE DOOR
void getDoor() {
	if (isStanding == false) {
		cout << "You should get up off the floor." << endl;
		cout << "\n\n\n";
		cout << "Actions: Stand, Door, Keys, Sleep" << endl;
		cin >> playerInput;
		cout << "\n\n";

		if (playerInput == "stand" || playerInput == "Stand") {
			standUp();
		}
		if (playerInput == "door" || playerInput == "Door") {
			getDoor();
		}
		if (playerInput == "keys" || playerInput == "Keys") {
			getKeys();
		}
		if (playerInput == "sleep" || playerInput == "Sleep") {
			goSleep();
		}
		else
		{
			dead();
		}
	}
	//THE PLAYER HAS TO BE STANDING AND HAVE THE KEYS TO USE THE DOOR
	if (isStanding == true) {
		//PLAYER DOES NOT HAVE THE KEYS
		if (hasKeys == false) {
			cout << "Don't you think you should take your keys with you?" << endl;
			cout << "\n\n\n";
			cout << "Actions: Keys, Sleep" << endl;

			if (playerInput == "sleep" || playerInput == "Sleep") {
				goSleep();
			}
			if (playerInput == "keys" || playerInput == "Keys") {
				getKeys();
			}
			else
			{
				dead();
			}
		}
		//PLAYER HAS THE KEYS
		if (hasKeys == true) {
			cout << "You approach the door and reach for the handle..." << endl;
			cout << "Turning it slowly, you open the barrier and step through into sunlight." << endl;
			system("Pause");
			cout << "But then a voice behind you squeals," << endl;
			system("Color 0C");
			string spooky = "D O N ' T    L E A V E . . .";
			int x = 0;
			while (spooky[x] != '\0')
			{
				cout << spooky[x];
				Sleep(150);
				x++;
			};
			cout << "\n\n\n";
			system("Pause");
			cout << "\n\n\n";
			system("Color 0F");

			winnable();
		}
	}
}

//FUNCTION THAT ALLOWS THE PLAYER TO LOOK AROUND
void lookAround() {
	hasLook = true;
	cout << "\n\n\n";
	cout << "You look at the furniture that surrounds you." << endl;
	cout << "There are keys on the table. They look like yours." << endl;
	cout << "The front door is up ahead." << endl;
	cout << "\n\n\n";

	//THE PLAYER OPTIONS IF THEY HAD ALREADY STOOD UP
	if (isStanding == true) {
		cout << "Actions: Door, Keys, Sleep" << endl;
		cin >> playerInput;
		
		if (playerInput == "keys" || playerInput == "Keys") {
			getKeys();
		}
		if (playerInput == "door" || playerInput == "Door") {
			getDoor();
		}
		if (playerInput == "sleep" || playerInput == "Sleep") {
			goSleep();
		}
		else
		{
			dead();
		}
	}

	//THE PLAYER OPTIONS IF THE PLAYER ISN'T STANDING YET
	if (isStanding == false) {
		cout << "Actions: Door, Keys, Stand, Sleep" << endl;
		cin >> playerInput;
		
		if (playerInput == "keys" || playerInput == "Keys") {
			getKeys();
		}
		if (playerInput == "door" || playerInput == "Door") {
			getDoor();
		}
		if (playerInput == "sleep" || playerInput == "Sleep") {
			goSleep();
		}
		if (playerInput == "stand" || playerInput == "Stand") {
			standUp();
		}
		else
		{
			dead();
		}
	}
}

//FUNCTION THAT ALLOWS THE PLAYER TO STAND UP
void standUp() {
	isStanding = true;
	cout << "Stretching out your legs, you slowly rise to your feet." << endl;
	cout << "You may have done so too quickly, you feel a little dizzy." << endl;
	cout << "The sensation quickly passes." << endl;
	cout << "\n\n\n";

	//WHAT THE PLAYER SEES IF THEY HAVEN'T LOOKED AROUND YET
	if (hasLook == false) {
		cout << "Actions: Look, Sleep" << endl;
		cin >> playerInput;
		
		if (playerInput == "look" || playerInput == "Look") {
			lookAround();
		}
		if (playerInput == "sleep" || playerInput == "Sleep") {
			cout << "\n\n\n";
			goSleep();
		}
		else
		{
			dead();
		}
	}
	//WHAT THE PLAYER SEES IF THEY HAVE ALREADY LOOKED AROUND
	if (hasLook == true) {
		cout << "Actions: Keys, Door, Sleep" << endl;
		cin >> playerInput;
		if (playerInput == "keys" || playerInput == "Keys") {
			getKeys();
		}
		if (playerInput == "door" || playerInput == "Door") {
			getDoor();
		}
		if (playerInput == "sleep" || playerInput == "Sleep") {
			goSleep();
		}
		else
		{
			dead();
		}
	}
}

//THE BEGINNING OF THE STORY
void beginning() {
	//startRoom = true;
	cout << "You wake up on the floor of what seems to be a regular old house." << endl;
	cout << "But it isn't your house...\n\n" << endl;
	system("Pause");

	cout << "How did you get here?" << endl;
	cout << "\n" << endl;
	cout << "Actions: Stand, Look, Sleep" << endl;
	cin >> playerInput;
	cout << "\n\n\n";

	if (playerInput == "stand" || playerInput == "Stand") {
		standUp();
	}
	if (playerInput == "look" || playerInput == "Look") {
		lookAround();
	}
	if (playerInput == "sleep" || playerInput == "Sleep") {
		goSleep();
	}
	else
	{
		dead();
	}
}

//TAKING THE PLAYER'S NAME
void enterName() {
	cout << "what is the name of your character?" << endl;
	cin >> playerName;
	cout << "\n\n\n";
}

//INITIALIZING THE PLAYER'S GAME
int main()
{
	cout << "Welcome to the 'Recollection' Text Adventure!" << endl;
	cout << "Created by Taylor McKenzie" << endl;
	system("Pause");
	cout << "\n\n\n";
	enterName();

	cout << "Hello there, " << playerName << "." << endl;
	system("Color 0C");
	string hello = "Please... Enjoy your stay.";
	int x = 0;
	while (hello[x] != '\0')
	{
		cout << hello[x];
		Sleep(150);
		x++;
	};
	cout << "\n\n\n";
	system("Pause");
	cout << "\n\n\n";
	system("Color 0F");

	beginning();
}