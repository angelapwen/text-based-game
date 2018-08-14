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
 and unsigned variables to 0. It should not be called.
*******************************************************************************/
Satchel::Satchel() {
	capacity = numUniqueWeapons = 0;
	knife = rope = wrench = revolver = candlestick = pipe = false;
}

/*******************************************************************************
The Satchel class 1-parameter constructor initializes the satchel's capacity
 to the int parameter. It initializes the number of unique weapons to 0 and
 sets all the bool variables to false.
*******************************************************************************/
Satchel::Satchel(unsigned capacityIn) {
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
Satchel::clearContents is a void function without parameters that is called
 when the random event happens that makes the player drop the bag. It clears
 all the weapons from the satchel and returns the unique weapon count to 0.
*******************************************************************************/
void Satchel::clearContents() {
	candlestick = rope = revolver = pipe = knife = wrench = false;
	numUniqueWeapons = 0;
	cout << "Uh oh! You dropped your satchel, butterfingers!" << endl;
	cout << "Someone might be coming." << endl;
	cout << "Pick up your satchel and forget the weapons." << endl;
	cout << "Hydra will take care of them." << endl;
	cout << "\nPress enter to pick up your satchel and hide." << endl;
	getchar();
	cout << "The footsteps you heard fade away. Phew!" << endl;
	cout << "Unfortunately, however, your satchel is now empty.\n" << endl;
}

/*******************************************************************************
Satchel::getNumUniqueWeapons is a function without parameters that
 returns the int value of the numUniqueWeapons variable. It resets the count
 of the number of unique weapons, and then adds one depending on each bool
 variable so it does not count repeated weapons. It will be called directly
 for the VectorSatchel and QueueSatchel classes and overridden in the
 BasicSatchel class.
*******************************************************************************/
int Satchel::getNumUniqueWeapons() {
	// Reset unique weapon count
	numUniqueWeapons = 0;

	if (knife) {
		numUniqueWeapons++;
	}
	if (wrench) {
		numUniqueWeapons++;
	}
	if (rope) {
		numUniqueWeapons++;
	}
	if (pipe) {
		numUniqueWeapons++;
	}
	if (revolver) {
		numUniqueWeapons++;
	}
	if (candlestick) {
		numUniqueWeapons++;
	}
	return numUniqueWeapons;
}

/*******************************************************************************
Satchel::~Satchel is a default virtual destructor because the Satchel class
 includes virtual functions.
*******************************************************************************/
Satchel::~Satchel() = default;
