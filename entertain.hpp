/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
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
