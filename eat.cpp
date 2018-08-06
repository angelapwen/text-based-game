/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/
#include "eat.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Eat::Eat() : Space() {
	foodItem = "default";
}

Eat::Eat(string nameIn, string weaponIn, string foodIn) : Space(nameIn, weaponIn)
{
	foodItem = foodIn;
}

string Eat::action() {
	cout << "You have come across" << foodItem << "." << endl;
	cout << "What would you like to do?" << endl;
	cout << "1. Do nothing. Food only slows you down." << endl;
	cout << "2. Eat it. This may be your last meal." << endl;

	return Space::action();
}