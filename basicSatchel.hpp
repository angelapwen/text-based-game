/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: basicSatchel.hpp is the header file for the basicSatchel
 * class. This class inherits publicly from the Satchel class and primarily
 * overrides its methods to add a weapon, retrieve the number of unique
 * weapons, and print the list of weapons.
*******************************************************************************/

#ifndef BASICSATCHEL_HPP
#define BASICSATCHEL_HPP

#include "satchel.hpp"

class basicSatchel : public Satchel {
public:
	basicSatchel();

	void addWeapon(std::string weapon) override;

	int getNumUniqueWeapons() override;

	void printWeapons() const override;
};


#endif //BASICSATCHEL_HPP
