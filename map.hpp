/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#ifndef MAP_HPP
#define MAP_HPP

#include <string>
#include <iostream>

class Map {
private:
	char board[25][57];

public:
	Map();

	void clearPlayer();

	void placeStudy();
	void placeLibrary();
	void placeBilliards();
	void placeConservatory();
	void placeBallroom();
	void placeKitchen();
	void placeDining();
	void placeLounge();
	void placeHall();

	void printBoard();
};


#endif //MAP_HPP
