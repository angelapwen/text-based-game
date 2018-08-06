/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#ifndef QUIET_HPP
#define QUIET_HPP

#include "space.hpp"

class Quiet : public Space{
private:
	std::string quietItem;

public:
	Quiet();

	Quiet(std::string nameIn, std::string weaponIn, std::string quietIn);

	std::string action() override;
};


#endif //FINAL_QUIET_HPP
