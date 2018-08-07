/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#include "satchel.hpp"

Satchel::Satchel() {
	capacity = numTotalWeapons = numUniqueWeapons = -1;
}

Satchel::Satchel(int capacityIn) {
	capacity = capacityIn;
	numTotalWeapons = numUniqueWeapons = 0;
}
