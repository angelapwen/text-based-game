/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: map.hpp is the Map class specification file. It specifies a
 * Map class that represents the floor plan of the Boddy Estate. It includes
 * a constructor, a method to clear the player's previous location, methods
 * to place the player in each room, and a method to print the board.
*******************************************************************************/

#ifndef MAP_HPP
#define MAP_HPP

#include <string>
#include <iostream>

class Map {
private:
	char board[25][57];
	void clearPlayer();

public:
	Map();

	void placeStudy();
	void placeLibrary();
	void placeBilliards();
	void placeConservatory();
	void placeBallroom();
	void placeKitchen();
	void placeDining();
	void placeLounge();
	void placeHall();

	void printBoard() const;
	void printKey() const;
};


#endif //MAP_HPP
