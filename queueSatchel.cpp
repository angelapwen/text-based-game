/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: queueSatchel.cpp is the implementation file for the
 * queueSatchel class, which inherits publicly from the Satchel class. It
 * represents the satchel using a deque STL container and overrides the pure
 * virtual functions to add a weapon, get the number of unique weapons, and
 * print weapons. Adding and removing a weapon from the bag in this class
 * operates like a queue (FIFO).
*******************************************************************************/

#include "queueSatchel.hpp"

using std::cout;
using std::endl;

/*******************************************************************************
The queueSatchel class default constructor calls the Satchel class 1-parameter
 constructor to initialize the satchel capacity to 4.
*******************************************************************************/
queueSatchel::queueSatchel() : Satchel(4) {

}

/*******************************************************************************
queueSatchel::addWeapon is a void method that takes a string parameter
 indicating the weapon the player has picked up. If the satchel is at
 capacity, the weapon at the front is removed. After this, the weapon is pushed
 to the back of the vector and the contents of the satchel are printed.
*******************************************************************************/
void queueSatchel::addWeapon(std::string weapon) {
	cout << "\nCongratulations! You have found a " << weapon << "." << endl;

	// If satchel size is 4 or greater, first pop front item in queue
	if (satchel.size() == 4) {
		cout << "Oops! Your Gold Satchel is already full with " << capacity << " "
		        "weapons." << endl;
		cout << "Before adding your new " << weapon << ", you will have to "
		     "drop the first weapon\nin your Gold Satchel." << endl;
		cout << "The weapon you drop is the " << satchel.front() << "." << endl;

		// Delete front weapon
		satchel.pop_front();

		// Update weapon status after one was deleted
		updateWeapons();

		cout << "Your current weapon list is:" << endl;
		printWeapons();
	}

	// Now vector should have maximum 3 weapons
	satchel.push_back(weapon);

	// Update bool variables to true if the new weapon was not a repeat
	if (weapon == "knife") {
		knife = true;
	}
	else if (weapon == "wrench") {
		wrench = true;
	}
	else if (weapon == "rope") {
		rope = true;
	}
	else if (weapon == "pipe") {
		pipe = true;
	}
	else if (weapon == "revolver") {
		revolver = true;
	}
	else if (weapon == "candlestick") {
		candlestick = true;
	}

	cout << "\nYour new " << weapon << " has been added to the satchel." << endl;

	// Print total weapons, list, and number of unique weapons
	cout << "Your total weapon count is: " << satchel.size() << "." <<
	     endl;
	cout << "Your current weapon list is:" << endl;
	printWeapons();
	cout << "The number of unique weapons in your bag is: " <<
	     getNumUniqueWeapons() << "." << endl;
}

/*******************************************************************************
vectorSatchel::updateWeapons is a void method without parameters. It is used
 to switch the bool flag off after a weapon is dropped from the bag, if
 necessary. It uses the count method to count each type of weapon. If the
 count is 0, the bool flag is flipped to off.
*******************************************************************************/
void queueSatchel::updateWeapons() {
	// Count weapons in deque
	long count;

	// Search for each weapon type in bag and set bool flag to false if not found
	count = std::count(satchel.begin(), satchel.end(), "knife");
	if (count == 0) {
		knife = false;
	}

	count = std::count(satchel.begin(), satchel.end(), "wrench");
	if (count == 0) {
		wrench = false;
	}

	count = std::count(satchel.begin(), satchel.end(), "rope");
	if (count == 0) {
		rope = false;
	}

	count = std::count(satchel.begin(), satchel.end(), "pipe");
	if (count == 0) {
		pipe = false;
	}

	count = std::count(satchel.begin(), satchel.end(), "revolver");
	if (count == 0) {
		revolver = false;
	}

	count = std::count(satchel.begin(), satchel.end(), "candlestick");
	if (count == 0) {
		candlestick = false;
	}
}

/*******************************************************************************
queueSatchel::getNumUniqueWeapons is a function without parameters that
 returns the int value of the numUniqueWeapons variable. It resets the count
 of the number of unique weapons, and then adds one depending on each bool
 variable so it does not count repeated weapons.
*******************************************************************************/
int queueSatchel::getNumUniqueWeapons() {
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
queueSatchel::printWeapons is a void function without parameters that prints
 all contents of the vector.
*******************************************************************************/
void queueSatchel::printWeapons() const {
	for (auto &i: satchel) {
		cout << "- " << i << endl;
	}
}