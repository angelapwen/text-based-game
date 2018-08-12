/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: game.hpp is the Game class specification file. It specifies a
 * Class that is composed of a Map pointer, a Satchel pointer, and various
 * Space pointers. It runs the game loop, allowing the user to pick a
 * Satchel, move throughout the board, and commit the murder.
*******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "quiet.hpp"
#include "eat.hpp"
#include "entertain.hpp"

#include "basicSatchel.hpp"
#include "vectorSatchel.hpp"
#include "queueSatchel.hpp"

#include "map.hpp"

#include <string>
#include <cstdlib> // std::rand

class Game {
private:
 	Map* map;

	Satchel* satchel;

	int steps; // Count number of moves that have passed
	Space* current; // Where the player is currently located

	Space* study;
	Space* library;
	Space* billiards;
	Space* conservatory;
	Space* ballroom;
	Space* kitchen;
	Space* dining;
	Space* lounge;
	Space* hall;

	bool murder; // True if murder has been committed
	bool discovery; // True if character has been found out before game ends
	char character; // Stores the type of character player has chosen

	void welcomeMenu() const;
	void characterChoice();
	void satchelChoice();
	void updateMap();
	void commitMurder();
	std::string weaponValidation() const;

public:
	Game();

	void startGame();

	int intValidation(int min, int max) const;
	void repeatMenu() const;

	~Game();
};


#endif //GAME_HPP
