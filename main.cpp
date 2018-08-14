/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: Clue: The Prequel is a text-based adventure game for the
 * command line. It is loosely based off of the popular murder mystery game
 * "Clue." The player plays Professor Peter Plum, an eccentric academic with
 * a dark, deceitful past. Professor Plum receives a mission to complete at
 * his brother-in-law Mr. Boddy's 30th birthday party.
*******************************************************************************/

#include <iostream>
#include <cstdlib> // srand()
#include <ctime> // time()
#include "game.hpp"

using std::cin;
using std::cout;
using std::endl;

int main() {
	// Set a random generator seed
	// Referenced from Program 3-32 of C++ Early Objects, 9th Edition
	unsigned seed;

	seed = static_cast<unsigned>(time(nullptr));
	srand(seed);

	// Construct and begin game
	Game game;
	game.startGame();

	// Give player the option to play again
	int repeatChoice = 0;

	do {
		game.repeatMenu();
		repeatChoice = game.intValidation(1,2);

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
