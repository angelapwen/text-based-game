/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "quiet.hpp"
#include "eat.hpp"
#include "entertain.hpp"
#include "basicSatchel.hpp"
#include "map.hpp"

class Game {
private:
 	Map* map;

	Satchel* satchel;

	int steps;
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

	bool murder;

public:
	Game();
	void welcomeMenu() const;

	void startGame();

	void updateBoard();

	void commitMurder();

	std::string weaponValidation() const;

	void repeatMenu() const;

	~Game();


};


#endif //GAME_HPP
