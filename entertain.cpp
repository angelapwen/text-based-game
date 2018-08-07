/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#include "entertain.hpp"

using std::string;
using std::cout;
using std::endl;

Entertain::Entertain() : Space() {
	gameItem = "default";
}

Entertain::Entertain(string nameIn, string weaponIn, string gameIn) :
		Space(nameIn, weaponIn)
{
	gameItem = gameIn;

}

string Entertain::action() {
	cout << "You have come across " << gameItem << "." << endl;
	cout << "What would you like to do?" << endl;
	cout << "1. Do nothing." << endl;
	cout << "2. Play " << gameItem << "." << endl;

	return Space::action();
}







