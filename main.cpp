/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.hpp"

using std::cin;
using std::cout;
using std::endl;

int intValidation (int min, int max);

int main() {
	// Set a random generator seed
	// Referenced from Program 3-32 of C++ Early Objects, 9th Edition
	unsigned seed;

	seed = static_cast<unsigned>(time(0));
	srand(seed);

	Game game;
	game.startGame();

	int repeatChoice = 0;

	do {
		game.repeatMenu();
		repeatChoice = intValidation(1,2);

		switch(repeatChoice) {
			case 1: {
				Game repeatGame;
				repeatGame.startGame();
				break;
			}
			case 2:
				break;
			default:
				break;
		}
	} while (repeatChoice != 2);

	return 0;
}

/*******************************************************************************
 * intValidation is a function with two int parameters that returns an int
 * value. It prompts the user for input and validates the input to be an
 * integer between the min and max parameters, and returns the valid value.
*******************************************************************************/
int intValidation(int min, int max) {
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
