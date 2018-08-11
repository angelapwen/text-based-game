/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#include "basicSatchel.hpp"

using std::string;
using std::endl;
using std::cout;

basicSatchel::basicSatchel() : Satchel(4) {
}

void basicSatchel::addWeapon(std::string weapon) {
	if (numUniqueWeapons >= capacity) {
		cout << "Sorry, your Bronze Satchel is full and you cannot pick up any "
			 "more weapons." << endl;
		cout << "You should focus on finding the room in which you will commit "
			 << "your murder." << endl;
	}

	else {
		if ((weapon == "knife")) {
			if (!knife) {
				cout << "Congratulations! You have picked up a knife." << endl;
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
				cout << "Congratulations! You have picked up a rope." << endl;
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
				cout << "Congratulations! You have picked up a wrench." << endl;
				wrench = true;
				numUniqueWeapons++;
			}
			// Else user already had a wrench
			else {
				cout << "You have picked up a wrench, but your satchel already "
				        "contained oned." << endl;
				cout << "Hydra has destroyed the spare wrench." << endl;
			}
		}
		else if ((weapon == "revolver")) {
			if (!revolver) {
				cout << "Congratulations! You have picked up a revolver." << endl;
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
				cout << "Congratulations! You have picked up a candlestick."
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
				cout << "Congratulations! You have picked up a lead pipe." << endl;
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

		cout << "Your total weapon count is: " << numUniqueWeapons << "." <<
		     endl;
		cout << "Your current weapon list is:" << endl;
		printWeapons();
	}
}

int basicSatchel::getNumUniqueWeapons() {
	return numUniqueWeapons;
}

void basicSatchel::printWeapons() const {
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
