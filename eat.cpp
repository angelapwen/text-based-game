/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: eat.hpp is the Eat class implementation file. It implements a
 * Class that inherits publicly from the Space abstract class. The rooms that will
 * be instantiated with this theme are the Dining Room, Kitchen, and Lounge.
*******************************************************************************/
#include "eat.hpp"

using std::cout;
using std::cin;
using std::endl;

/* The Eat class default constructor calls the Space class default
 * constructor and sets the foodItem member variable to default. */
Eat::Eat() : Space() {
	foodItem = "default";
}

/* The Eat class 3-parameter constructor calls the Space class 2-parameter
 * constructor and sets the foodItem member variable to the appropriate
 * string passed in. */
Eat::Eat(std::string nameIn, std::string weaponIn, std::string foodIn) : Space
(nameIn, weaponIn)
{
	foodItem = foodIn;
}

/* Eat::action() overrides Space::action. It displays the room's food item,
 * and the two options that the user has. It then calls Space::action. It is a
 * method without parameters that returns a string.*/
std::string Eat::action() {
	cout << "You have come across " << foodItem << "." << endl;
	cout << "What would you like to do?" << endl;
	cout << "1. Do nothing. Food only slows you down." << endl;
	cout << "2. Eat it. This may be your last meal." << endl;

	return Space::action();
}