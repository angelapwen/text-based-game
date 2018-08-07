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

