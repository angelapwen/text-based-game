/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: space.cpp is the Space Class implementation file. It implements
 * an abstract class Space that Classes Eat, Entertain, and Quiet will
 * publicly inherit from.
*******************************************************************************/

#include "space.hpp"

using std::string;

using std::cout;
using std::cin;
using std::endl;

/*******************************************************************************
The Space class default constructor should not be used as the Space class
 is an abstract class.
*******************************************************************************/
Space::Space() {
	name = "default";
	weapon = "default";
	top = right = left = bottom = corner = nullptr;
	newMove = nullptr;
	cornerAccess = false;
}

/*******************************************************************************
The Space class constructor with two parameters initializes the member
 variables of name and weapon with the appropriate parameters. It also sets
 the pointers top, right, left, bottom, corner, and newMove to nullptr.
 Access to the corner passageways should be off when the game begins.
*******************************************************************************/
Space::Space(string nameIn, string weaponIn) {
	name = nameIn;
	weapon = weaponIn;
	top = right = left = bottom = corner = nullptr;
	newMove = nullptr;
	cornerAccess = false;
}

/*******************************************************************************
The following 5 functions are mutator functions setting the Space pointers
 to Top, Bottom, Left, Right, and Corner for each Space. They will be
 called to link the Spaces together after they are constructed.
*******************************************************************************/
void Space::setTop(Space *roomIn) {
	top = roomIn;
}

void Space::setBottom(Space *roomIn) {
	bottom = roomIn;
}

void Space::setLeft(Space *roomIn) {
	left = roomIn;
}

void Space::setRight(Space *roomIn) {
	right = roomIn;
}

void Space::setCorner(Space *roomIn) {
	corner = roomIn;
}

/*******************************************************************************
Space::roomWelcome is a void function without parameters that simply displays
 the room name when the player enters.
*******************************************************************************/
void Space::roomWelcome() const {
	cout << "\nYou have entered the " << name << "." << endl;
}

/*******************************************************************************
getName() and getWeapon() are accessor functions returning strings for
 their appropriate member variables.
*******************************************************************************/
string Space::getName() const {
	return name;
}
string Space::getWeapon() const {
	return weapon;
}

/*******************************************************************************
Space::setCornerAccess is a void function that takes a char indicating whether
 the corner passageways should be displayed as an option for the user. It
 is called every round before the player makes a move.
*******************************************************************************/
void Space::setCornerAccess (char access) {
	if (access == 'y') {
		cornerAccess = true;
	}
	else {
		cornerAccess = false;
	}
}

/*******************************************************************************
/* Space::makeMove is a method without parameters that returns a char indicating
 * which direction the player has elected to travel in. It displays the
 * options for the player to move and takes the player's choice.
*******************************************************************************/
char Space::makeMove() const {
	cout << "Your options are: " << endl;

	// Print the options available in the current room
	if (this->top != nullptr) {
		cout << "- Top: " ;
		cout << "This would lead to the " << this->top->name << "." << endl;
	}
	if (this->bottom != nullptr) {
		cout << "- Bottom: ";
		cout << "This would lead to the " << this->bottom->name << "." << endl;
	}
	if (this->left != nullptr) {
		cout << "- Left: ";
		cout << "This would lead to the " << this->left->name << "." << endl;
	}
	if (this->right != nullptr) {
		cout << "- Right: ";
		cout << "This would lead to the " << this->right->name << "." << endl;
	}

	// Display corner option only if the bool is true
	if (cornerAccess) {
		if (this->corner != nullptr) {
			cout << "- Corner: ";
			cout << "This would lead to the " << this->corner->name << "." << endl;
		}
	}

	cout << "- Exit: ";
	cout << "You may choose the Emergency Exit and leave your mission "
			"incomplete." << endl;

	cout << "Enter only Top, Bottom, Left, Right, Corner, or Exit." << endl;

	string choice = moveValidation();

	// Return the char value of the validated move
	if (choice == "Top") {
		return 't';
	}

	else if (choice == "Bottom") {
		return 'b';
	}

	else if (choice == "Left") {
		return 'l';
	}

	else if (choice == "Right") {
		return 'r';
	}

	// Else user picked corner
	else if (choice == "Corner") {
		return 'c';
	}

	// Else user chose to exit
	else {
		return 'e';
	}
}

/*******************************************************************************
Space::moveValidation is a method without parameters that returns the validated
 string. It checks if the user's input is one of the six accepted strings,
 and then if so, checks to see if it leads to another Space. When the input
 is validated, it returns the input.
*******************************************************************************/
string Space::moveValidation() const{
	string input;

	bool isNull = true; // Bool flag to break loop when input is valid

	while(isNull) {
		cout << "\nMake your choice: ";
		cin >> input;

		// Try again if input is not one of the directions
		while (input != "Top" && input != "Bottom" && input != "Left" && input !=
	          "Right" && input != "Corner" && input != "Exit") {
			cout << "Input must be a valid direction for this room." << endl;
			cout << "Please try again: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> input;
		}

		cin.clear();
		cin.ignore(256, '\n');

		// Check if direction input points to nullptr
		if (input == "Top" && top == nullptr) {
			cout << "Top does not lead anywhere. Try again.";
		}
		else if (input == "Bottom" && bottom == nullptr) {
			cout << "Bottom does not lead anywhere. Try again.";
		}
		else if (input == "Left" && left == nullptr) {
			cout << "Left does not lead anywhere. Try again.";
		}
		else if (input == "Right" && right == nullptr) {
			cout << "Right does not lead anywhere. Try again.";
		}
		// Else if corner does not lead anywhere
		else if (input == "Corner" && corner == nullptr) {
			cout << "Corner does not lead anywhere. Try again.";
		}
		// Else if corner is an option, but access is off
		else if (input == "Corner" && corner != nullptr && !cornerAccess) {
			cout << "Nice try, but you can't access the secret corner passageway "
			  "now!" << endl;
		}
		// If it doesn't point to nullptr, break loop
		else {
			isNull = false;
		}
	}
	return input;
}

/*******************************************************************************
The following 5 functions are accessor functions returning the Space pointer
 * to the next Space in the direction the user has chosen.
*******************************************************************************/
Space* Space::getTop() {
	newMove = this->top;
	return newMove;
}

Space* Space::getBottom() {
	newMove = this->bottom;
	return newMove;
}

Space* Space::getLeft() {
	newMove = this->left;
	return newMove;
}

Space* Space::getRight() {
	newMove = this->right;
	return newMove;
}

Space* Space::getCorner() {
	newMove = this->corner;
	return newMove;
}

/*******************************************************************************
Space::action is a function without parameters that returns the string
 indicating whether the user has picked up a weapon in the room, based off of
 the user's choice of action. It will be called in the inherited classes' action
 function overrides.
*******************************************************************************/
std::string Space::action() {
	string received;

	int actionChoice = intValidation(1, 2);

	switch (actionChoice) {
		case 1:
			// User made the "wrong" choice and does not receive a weapon
			received = "none";
			break;
		case 2:
			// Return the string of the weapon that the current Space includes
			received = getWeapon();
			break;
		default:
			break;
	}

	return received;
}

/*******************************************************************************
Space::intValidation is a function with two int parameters that returns an int
 value. It prompts the user for input and validates the input to be an
 integer between the min and max parameters, and returns the valid value.
*******************************************************************************/
int Space::intValidation(int min, int max) {
	cout << "Make your choice: ";

	int input;
	cin >> input;

	// Try again if input is out of range or fails
	while (input < min || input > max || cin.fail()) {
		cout << "Input must be an integer between " << min << " and "
		     << max << "." << endl;
		cout << "Please try again: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> input;
	}

	// Flush buffer after successful input
	cin.clear();
	cin.ignore(256, '\n');

	return input;
}