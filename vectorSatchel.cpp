/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#include "vectorSatchel.hpp"

using std::cout;
using std::endl;

vectorSatchel::vectorSatchel() : Satchel(5) {
}

void vectorSatchel::addWeapon(std::string weapon) {
	cout << "\nCongratulations! You have found a " << weapon << "." << endl;

	// If vector size is 5, call randomDrop
	if (satchel.size() == 5) {
		cout << "Oops! Your satchel is already full with " << capacity << " "
				"weapons." << endl;
		cout << "Before adding your new " << weapon << ", you will have to "
				 "randomly drop one of your existing weapons." << endl;
		randomDrop();
	}

	// Now vector should have maximum four weapons
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

void vectorSatchel::randomDrop() {
	// Randomly shuffle the contents of vector
	std::random_shuffle(satchel.begin(),satchel.end());

	cout << "A " << satchel.back() << " has been selected at random for you "
												 "to drop." << endl;

	// Delete last element
	satchel.pop_back();

	// Update weapon status after one was deleted
	updateWeapons();

	cout << "Your current weapon list is:" << endl;
	printWeapons();
}

void vectorSatchel::updateWeapons() {
	// Sort bag for binary searchlet
	std::sort(satchel.begin(),satchel.end());

	// Search for each weapon type in bag and set bool flag to false if not found
	if (!std::binary_search(satchel.begin(),satchel.end(),"knife")) {
		knife = false;
	}
	if (!std::binary_search(satchel.begin(),satchel.end(),"wrench")) {
		wrench = false;
	}
	if (!std::binary_search(satchel.begin(),satchel.end(),"rope")) {
		rope = false;
	}
	if (!std::binary_search(satchel.begin(),satchel.end(),"pipe")) {
		pipe = false;
	}
	if (!std::binary_search(satchel.begin(),satchel.end(),"revolver")) {
		revolver = false;
	}
	if (!std::binary_search(satchel.begin(),satchel.end(),"candlestick")) {
		candlestick = false;
	}
}

int vectorSatchel::getNumUniqueWeapons() {
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

void vectorSatchel::printWeapons() const {
	// Print vector
	for (auto i: satchel) {
		cout << "- " << i << endl;
	}
}
