/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#include "queueSatchel.hpp"

using std::cout;
using std::endl;

queueSatchel::queueSatchel() : Satchel(4) {

}

void queueSatchel::addWeapon(std::string weapon) {
	cout << "\nCongratulations! You have found a " << weapon << "." << endl;

	// If satchel size is 4 or greater, first pop front item in queue
	if (satchel.size() == 4) {
		cout << "Oops! Your Gold Satchel is already full with " << capacity << " "
		        "weapons." << endl;
		cout << "Before adding your new " << weapon << ", you will have to "
		     "drop the first weapon\nin your Gold Satchel." << endl;
		cout << "The weapon you drop is the " << satchel.front() << "." << endl;

		// Delete last element
		satchel.pop_front();

		// Update weapon status after one was deleted
		updateWeapons();

		cout << "Your current weapon list is:" << endl;
		printWeapons();
	}

	// Now vector should have maximum 3 weapons
	satchel.push_back(weapon);

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

	cout << "Your total weapon count is: " << satchel.size() << "." <<
	     endl;
	cout << "Your current weapon list is:" << endl;
	printWeapons();
	cout << "The number of unique weapons in your bag is: " <<
	     getNumUniqueWeapons() << "." << endl;
}

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

void queueSatchel::printWeapons() const {
	for (auto &i: satchel) {
		cout << "- " << i << endl;
	}
}

