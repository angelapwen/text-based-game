/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#ifndef BASICSATCHEL_HPP
#define BASICSATCHEL_HPP

#include "satchel.hpp"

class basicSatchel : public Satchel {
private:


public:
	basicSatchel();
	void addWeapon(std::string weapon) override;

	int getNumUniqueWeapons() override;

	void printWeapons() const override;
};


#endif //BASICSATCHEL_HPP