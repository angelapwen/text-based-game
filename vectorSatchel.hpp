/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#ifndef VECTORSATCHEL_HPP
#define VECTORSATCHEL_HPP

#include "satchel.hpp"
#include <vector>
#include <algorithm>
#include <cstdlib>

class vectorSatchel: public Satchel {
private:
	std::vector<std::string> satchel;

public:
	vectorSatchel();

	void addWeapon(std::string weapon) override;
	void randomDrop();
	void updateWeapons();

	int getNumUniqueWeapons() override;

	void printWeapons() const override;
};


#endif //VECTORSATCHEL_HPP
