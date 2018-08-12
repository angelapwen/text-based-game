/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: satchel.cpp is the implementation file for the Satchel abstract
 * class. The basicSatchel, queueSatchel, and vectorSatchel classes will inherit
 * from this class.
*******************************************************************************/

#include "satchel.hpp"

using std::cout;
using std::endl;

/*******************************************************************************
The Satchel class default constructor initializes the bool variables to false
 and int variables to -1. It should not be called as Satchel.
*******************************************************************************/
Satchel::Satchel() {
	capacity = numUniqueWeapons = -1;
	knife = rope = wrench = revolver = candlestick = pipe = false;
}

/*******************************************************************************
The Satchel class 1-parameter constructor initializes the satchel's capacity
 to the int parameter. It initializes the number of unique weapons to 0 and
 sets all the bool variables to false.
*******************************************************************************/
Satchel::Satchel(int capacityIn) {
	capacity = capacityIn;
	numUniqueWeapons = 0;
	knife = rope = wrench = revolver = candlestick = pipe = false;
}

/*******************************************************************************
The following 6 functions are accessor functions returning the bool value of
 the weapon they are accessing.
*******************************************************************************/
bool Satchel::getCandlestick() const {
	return candlestick;
}

bool Satchel::getRope() const {
	return rope;
}

bool Satchel::getRevolver() const {
	return revolver;
}

bool Satchel::getPipe() const {
	return pipe;
}

bool Satchel::getKnife() const {
	return knife;
}

bool Satchel::getWrench() const {
	return wrench;
}

/*******************************************************************************
Satchel::addCapacity() is a void function without parameters that is called
 only when the player chooses the Colonel Mustard disguise. It increments the
 capacity of the satchel by 1.
*******************************************************************************/
void Satchel::addCapacity() {
	capacity++;
	cout << "Your chosen satchel has a new capacity of " << capacity << "." <<
	     endl;
}

/*******************************************************************************
Satchel::~Satchel is a default virtual destructor because the Satchel class
 includes virtual functions.
*******************************************************************************/
Satchel::~Satchel() = default;
