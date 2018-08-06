/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/
#include "quiet.hpp"

using std::cout;
using std::endl;

Quiet::Quiet() : Space() {
	quietItem = "default";
}

Quiet::Quiet(std::string nameIn, std::string weaponIn, std::string quietIn) :
		Space(nameIn, weaponIn) {
	quietItem = quietIn;
}

std::string Quiet::action() {
	cout << "You notice " << quietItem << " nearby." << endl;
	cout << "Would you like to use it for some peace and quiet?" << endl;
	cout << "1. Yes, it's a good time for me to relax." << endl;
	cout << "2. No, that sounds like a bad idea." << endl;

	return Space::action();
}


