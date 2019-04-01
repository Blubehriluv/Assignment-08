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

// Color References
// 0C = Red on Black,  0F = White on Black
void beginning();

void dead() {
	system("Color 0C");
	cout << "You died" << endl;
	startRoom = false;
	hallway = false;
	hasLook = false;
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

void goSleep() {
	cout << "You lay in the fetal position until you drift off into slumber." << endl;
	cout << "If you don't know where you are, why would you sleep?" << endl;
	system("Pause");
	cout << "\n\n\n";
	dead();
}

void lookAround() {
	cout << "\n\n\n";
	cout << "You look at the furniture that surrounds you." << endl;
	cout << "There are keys on the table. They look like yours." << endl;
	cout << "The front door is up ahead." << endl;
	
	if (isStanding == true) {
		cout << "Actions: "
	}

	if (isStanding == false) {
		cout << "Actions: Door, Keys, Stand, Sleep" << endl;
	}
}

void standUp() {
	isStanding = true;
	cout << "Stretching out your legs, you slowly rise to your feet." << endl;
	cout << "You may have done so too quickly, you feel a little dizzy." << endl;
	cout << "The sensation quickly passes." << endl;
	cout << "\n\n";

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
	}

	if (hasLook == true) {
		cout << "Actions: Keys, Door, Sleep" << endl;
		cin >> playerInput;
		if (playerInput == ) {

		}
	}
}

void beginning() {
	//startRoom = true;
	cout << "You wake up in what seems to be a regular old house." << endl;
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
		hasLook = true;
		lookAround();
	}
	if (playerInput == "sleep" || playerInput == "Sleep") {
		goSleep();
	}
}

void enterName() {
	cout << "what is the name of your character?" << endl;
	cin >> playerName;
	cout << "\n\n\n";
}

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
