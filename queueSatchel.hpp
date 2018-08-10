/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#ifndef QUEUESATCHEL_HPP
#define QUEUESATCHEL_HPP

#include "satchel.hpp"
#include <deque>
#include <algorithm>

class queueSatchel: public Satchel {
private:
	std::deque<std::string> satchel;

public:
	queueSatchel();

	void addWeapon(std::string weapon) override;
	void updateWeapons();

	int getNumUniqueWeapons() override;

	void printWeapons() const override;

};


#endif //QUEUESATCHEL_HPP
