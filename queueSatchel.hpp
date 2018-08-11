/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: queueSatchel.hpp is the header file for the queueSatchel
 * class, which inherits publicly from the Satchel class. It represents the
 * satchel using a deque STL container and overrides the pure virtual
 * functions to add a weapon, get the number of unique weapons, and print
 * weapons. Adding and removing a weapon from the bag in this class operates
 * like a queue (FIFO).
*******************************************************************************/

#ifndef QUEUESATCHEL_HPP
#define QUEUESATCHEL_HPP

#include "satchel.hpp"
#include <deque>
#include <algorithm> // std::count

class queueSatchel: public Satchel {
private:
	std::deque<std::string> satchel; // Represent satchel with deque of strings

public:
	queueSatchel();

	void addWeapon(std::string weapon) override;
	void updateWeapons();

	int getNumUniqueWeapons() override;

	void printWeapons() const override;
};


#endif //QUEUESATCHEL_HPP
