/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#include "space.hpp"

using std::string;

using std::cout;
using std::cin;
using std::endl;

Space::Space() {
	name = "default";
	weapon = "default";
	top = right = left = bottom = corner = nullptr;
	newMove = nullptr;
}

Space::Space(string nameIn, string weaponIn) {
	name = nameIn;
	weapon = weaponIn;
	top = right = left = bottom = corner = nullptr;
	newMove = nullptr;
}


string Space::getName() const {
	return name;
}

string Space::getWeapon() const {
	return weapon;
}

char Space::makeMove() const {
	// If pointer != nullptr, then display room option
			// Prompt string input from user
					// If string input != top bottom left right corner, try again
							// If this->input == nullptr, try again
									// Return move as int (enum maybe)

	cout << "\nIt is time to move to another room." << endl;
	cout << "Your options for moving are: " << endl;

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
	if (this->corner != nullptr) {
		cout << "- Corner: " ;
		cout << "This would lead to the " << this->corner->name << "." << endl;
	}

	cout << "- Exit: ";
	cout << "You may choose the Emergency Exit and leave your mission "
			"incomplete." << endl;

	cout << "Enter only Top, Bottom, Left, Right, Corner, or Exit." << endl;

	string choice = moveValidation();

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
		else if (input == "Corner" && corner == nullptr) {
			cout << "Corner does not lead anywhere. Try again.";
		}
		// If it doesn't point to nullptr, break loop
		else {
			isNull = false;
		}
	}
	return input;
}

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

std::string Space::action() {
	string received;

	int actionChoice = intValidation(1, 2);

	switch (actionChoice) {
		case 1:
			received = "none";
			break;
		case 2:
			received = getWeapon();
			break;
		default:
			break;
	}

	return received;
}

/*******************************************************************************
 * intValidation is a function with two int parameters that returns an int
 * value. It prompts the user for input and validates the input to be an
 * integer between the min and max parameters, and returns the valid value.
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

void Space::roomWelcome() const {
	cout << "\nYou have entered the " << name << "." << endl;
}