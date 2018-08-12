/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: basicSatchel.hpp is the implementation file for the basicSatchel
 * class. This class inherits publicly from the Satchel class and primarily
 * overrides its methods to add a weapon, retrieve the number of unique
 * weapons, and print the list of weapons.
*******************************************************************************/

#include "basicSatchel.hpp"

using std::string;
using std::endl;
using std::cout;

/*******************************************************************************
The BasicSatchel class default constructor calls the Satchel class 1-parameter
 constructor to initialize the satchel capacity to 4.
*******************************************************************************/
BasicSatchel::BasicSatchel() : Satchel(4) {
}

/*******************************************************************************
BasicSatchel::addWeapon is a void function with a string parameter indicating
 the weapon the user has picked up. If the satchel is at capacity, the
 satchel does not add the weapon. If the satchel already contains this
 weapon, the satchel does not add the weapon.
*******************************************************************************/
void BasicSatchel::addWeapon(std::string weapon) {
	if (numUniqueWeapons >= capacity) {
		cout << "You have come across a " << weapon << ", but your Bronze "
		"Satchel\nis full and you cannot pick up any more weapons." << endl;
		cout << "You should focus on finding the room in which you will commit "
			 << "your murder." << endl;
		cout << "Hydra has destroyed the spare " << weapon << "." << endl;
	}

	// If user picks up weapon successfully, increment number of unique weapons
	else {
		if ((weapon == "knife")) {
			if (!knife) {
				cout << "Congratulations! You have added a knife to your Bronze "
				"Satchel."	<< endl;
				knife = true;
				numUniqueWeapons++;
			}
			// Else user already had a knife
			else {
				cout << "You have picked up a knife, but your satchel already "
				        "contained one." << endl;
				cout << "Hydra has destroyed the spare knife." << endl;
			}
		}
		else if ((weapon == "rope")) {
			if (!rope) {
				cout << "Congratulations! You have added a rope to your Bronze "
				"Satchel."	<< endl;
				rope = true;
				numUniqueWeapons++;
			}
				// Else user already had rope
			else {
				cout << "You have picked up a rope, but your satchel already "
				        "contained one." << endl;
				cout << "Hydra has destroyed the spare rope." << endl;
			}
		}
		else if ((weapon == "wrench")) {
			if (!wrench) {
				cout << "Congratulations! You have added a wrench to your Bronze "
				"Satchel."	<< endl;
				wrench = true;
				numUniqueWeapons++;
			}
			// Else user already had a wrench
			else {
				cout << "You have picked up a wrench, but your satchel already "
				        "contained one." << endl;
				cout << "Hydra has destroyed the spare wrench." << endl;
			}
		}
		else if ((weapon == "revolver")) {
			if (!revolver) {
				cout << "Congratulations! You have added a revolver to your "
				"Bronze Satchel."	<< endl;
				revolver = true;
				numUniqueWeapons++;
			}
			// Else user already had a revolver
			else {
				cout << "You have picked up a revolver, but your satchel already "
				        "contained one." << endl;
				cout << "Hydra has destroyed the spare revolver." << endl;
			}
		}
		else if ((weapon == "candlestick")) {
			if (!candlestick) {
				cout << "Congratulations! You have added a candlestick to your "
				"Bronze Satchel."
				     << endl;
				candlestick = true;
				numUniqueWeapons++;
			}
			// Else user already had a candlestick
			else {
				cout << "You have picked up a candlestick, but your satchel already "
						   "contained one." << endl;
				cout << "Hydra has destroyed the spare candlestick." << endl;
			}
		}
		else if ((weapon == "pipe")) {
			if (!pipe) {
				cout << "Congratulations! You have added a lead pipe to your "
				"Bronze Satchel." << endl;
				pipe = true;
				numUniqueWeapons++;
			}
				// Else user already had a pipe
			else {
				cout << "You have picked up a lead pipe, but your satchel already "
				        "contained one." << endl;
				cout << "Hydra has destroyed the spare lead pipe." << endl;
			}
		}

		// Print count and weapon list
		cout << "Your total weapon count is: " << numUniqueWeapons << "." <<
		     endl;
		cout << "Your Bronze Satchel currently contains:" << endl;
		printWeapons();
	}
}

/*******************************************************************************
BasicSatchel::getNumUniqueWeapons is a function without parameters that
 returns the int value of the numUniqueWeapons member variable.
*******************************************************************************/
int BasicSatchel::getNumUniqueWeapons() {
	return numUniqueWeapons;
}

/*******************************************************************************
BasicSatchel::printWeapons is a void function without parameters that prints
 the list of weapons in the satchel.
*******************************************************************************/
void BasicSatchel::printWeapons() const {
	if (candlestick) {
		cout << "- candlestick" << endl;
	}
	if (knife) {
		cout << "- knife" << endl;
	}
	if (revolver) {
		cout << "- revolver" << endl;
	}
	if (rope) {
		cout << "- rope" << endl;
	}
	if (wrench) {
		cout << "- wrench" << endl;
	}

	if (pipe) {
		cout << "- pipe" << endl;
	}
}