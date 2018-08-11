/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: entertain.hpp is the Entertain class header file. It
 * specifies a Class that inherits publicly from the Space abstract class. The
 * rooms that will be instantiated with this theme are the Hall, Ballroom,
 * and Billiard Room.
*******************************************************************************/

#ifndef ENTERTAIN_HPP
#define ENTERTAIN_HPP

#include "space.hpp"

class Entertain : public Space {
private:
	std::string gameItem;

public:
	Entertain();

	Entertain(std::string nameIn, std::string weaponIn, std::string gameIn);

	std::string action() override;
};


#endif //ENTERTAIN_HPP
