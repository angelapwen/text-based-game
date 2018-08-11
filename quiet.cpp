/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: quiet.cpp is the Quiet class implementation file. It
 * implements a Class that inherits publicly from the Space abstract class. The
 * rooms that will be instantiated with this theme are the Study, Library, and
 * Conservatory.
*******************************************************************************/
#include "quiet.hpp"

using std::cout;
using std::endl;

/* The Quiet class default constructor calls the Space class default
 * constructor and sets the quietItem member variable to default. */
Quiet::Quiet() : Space() {
	quietItem = "default";
}

/* The Quiet class 3-parameter constructor calls the Space class 2-parameter
 * constructor and sets the quietItem member variable to the appropriate
 * string passed in. */
Quiet::Quiet(std::string nameIn, std::string weaponIn, std::string quietIn) :
		Space(nameIn, weaponIn) {
	quietItem = quietIn;
}

/* Quiet::action() overrides Space::action. It displays the room's quiet item,
 * and the two options that the user has. It then calls Space::action. It is a
 * method without parameters that returns a string.*/
std::string Quiet::action() {
	cout << "You notice " << quietItem << " nearby." << endl;
	cout << "Would you like to use it for some peace and quiet?" << endl;
	cout << "1. Yes, it's a good time for me to relax." << endl;
	cout << "2. No, that sounds like a bad idea." << endl;

	return Space::action();
}


