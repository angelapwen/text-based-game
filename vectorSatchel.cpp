/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: vectorSatchel.cpp is the implementation file for the
 * vectorSatchel class. It inherits publicly from the Satchel abstract class.
 * It represents the satchel using a vector of strings and overrides the pure
 * virtual functions to add a weapon, get the number of unique weapons, and
 * print weapons.
*******************************************************************************/

#include "vectorSatchel.hpp"

using std::cout;
using std::endl;

/*******************************************************************************
The VectorSatchel class default constructor calls the Satchel class 1-parameter
 constructor to initialize the satchel capacity to 5.
*******************************************************************************/
VectorSatchel::VectorSatchel() : Satchel(5) {
}

/*******************************************************************************
VectorSatchel::addWeapon is a void method that takes a string parameter
 indicating the weapon the player has picked up. If the satchel is at
 capacity, the randomDrop method is called. After this, the weapon is pushed
 to the back of the vector and the contents of the satchel are printed.
*******************************************************************************/
void VectorSatchel::addWeapon(std::string weapon) {
	cout << "\nCongratulations! You have found a " << weapon << "." << endl;

	// If vector is at capacity, call randomDrop
	if (satchel.size() == capacity) {
		cout << "Oops! Your Silver Satchel is already full with " << capacity <<
		     " weapons." << endl;
		cout << "Before adding your new " << weapon << ", you will have to "
				 "randomly drop one of your existing weapons." << endl;
		randomDrop();
	}

	// Now vector should have maximum four weapons
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

	cout << "\nYour new " << weapon << " has been added to the Silver Satchel."
												<< endl;

	// Print total weapons, list, and number of unique weapons
	cout << "Your total weapon count is: " << satchel.size() << "." <<
	     endl;
	cout << "Your current weapon list is:" << endl;
	printWeapons();
	cout << "The number of unique weapons in your Silver Satchel is: " <<
	     getNumUniqueWeapons() << "." << endl;
}

/*******************************************************************************
VectorSatchel::randomDrop is a void function without parameters. It chooses a
 random weapon to drop within the vector by using the random_shuffle function
 and then popping the last weapon.
*******************************************************************************/
void VectorSatchel::randomDrop() {
	// Randomly shuffle the contents of vector
	std::random_shuffle(satchel.begin(),satchel.end());

	cout << "A " << satchel.back() << " has been selected at random for you "
												 "to drop." << endl;

	// Delete last element
	satchel.pop_back();

	// Update weapon status after one was deleted
	updateWeapons();

	// Print current weapons
	cout << "Your current weapon list is:" << endl;
	printWeapons();
}

/*******************************************************************************
VectorSatchel::updateWeapons is a void method without parameters. It is used
 to switch the bool flag off after a weapon is dropped from the bag, if
 necessary. It first calls the sort function, and then binary search to find
 each weapon.
*******************************************************************************/
void VectorSatchel::updateWeapons() {
	// Sort bag for binary search
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

/*******************************************************************************
VectorSatchel::getNumUniqueWeapons is a function without parameters that
 returns the int value of the numUniqueWeapons variable. It resets the count
 of the number of unique weapons, and then adds one depending on each bool
 variable so it does not count repeated weapons.
*******************************************************************************/
int VectorSatchel::getNumUniqueWeapons() {
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
VectorSatchel::clearContents is a void function without parameters that calls
 Satchel::clearContents but also pops off all the items in the vector.
*******************************************************************************/
void VectorSatchel::clearContents() {
	Satchel::clearContents();
	satchel.clear();
}

/*******************************************************************************
VectorSatchel::printWeapons is a void function without parameters that prints
 all contents of the vector.
*******************************************************************************/
void VectorSatchel::printWeapons() const {
	// Print vector
	for (auto &i: satchel) {
		cout << "- " << i << endl;
	}
}


