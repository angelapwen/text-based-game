/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: vectorSatchel.hpp is the header file for the vectorSatchel
 * class. It inherits publicly from the Satchel abstract class. It represents
 * the satchel using a vector of strings and overrides the pure virtual
 * functions to add a weapon, get the number of unique weapons, and print
 * weapons.
*******************************************************************************/

#ifndef VECTORSATCHEL_HPP
#define VECTORSATCHEL_HPP

#include "satchel.hpp"
#include <vector>
#include <algorithm> // std::random_shuffle, std::sort, std::binary_search

class VectorSatchel: public Satchel {
private:
	std::vector<std::string> satchel; // Represent satchel with vector of strings
	void randomDrop();
	void updateWeapons();

public:
	VectorSatchel();

	void addWeapon(std::string weapon) override;

	void clearContents() override;

	void printWeapons() const override;
};


#endif //VECTORSATCHEL_HPP
