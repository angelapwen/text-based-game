/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: entertain.cpp is the Entertain class implementation file. It
 * specifies a Class that inherits publicly from the Space abstract class. The
 * rooms that will be instantiated with this theme are the Hall, Ballroom,
 * and Billiard Room.
*******************************************************************************/

#include "entertain.hpp"

using std::cout;
using std::endl;

/* The Entertain class default constructor calls the Space class default
 * constructor and sets the gameItem member variable to default. */
Entertain::Entertain() : Space() {
	gameItem = "default";
}

/* The Entertain class 3-parameter constructor calls the Space class
 * 2-parameter constructor and sets the gameItem member variable to the
 * appropriate string passed in. */
Entertain::Entertain(std::string nameIn, std::string weaponIn, std::string
gameIn) : Space(nameIn, weaponIn)
{
	gameItem = gameIn;

}

/* Entertain::action() overrides Space::action. It displays the room's game
 * item, and the two options that the user has. It then calls Space::action.
 * It is a method without parameters that returns a string. */
std::string Entertain::action() {
	cout << "You have come across " << gameItem << "." << endl;
	cout << "What would you like to do?" << endl;
	cout << "1. Do nothing. It's too dangerous." << endl;
	cout << "2. You're under a lot of pressure. Entertain yourself for a bit. "
			<< endl;

	return Space::action();
}







