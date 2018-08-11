/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: eat.hpp is the Eat class header file. It specifies a Class
 * that inherits publicly from the Space abstract class. The rooms that will
 * be instantiated with this theme are the Dining Room, Kitchen, and Lounge.
*******************************************************************************/

#ifndef EAT_HPP
#define EAT_HPP

#include "space.hpp"

class Eat: public Space{
private:
	std::string foodItem;

public:
	Eat();

	Eat(std::string nameIn, std::string weaponIn, std::string foodIn);

	std::string action() override;
};


#endif //EAT_HPP
