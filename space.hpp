/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include <iostream>

class Space {
protected:
	std::string name;
	std::string weapon;
	Space* top;
	Space* right;
	Space* left;
	Space* bottom;
	Space* corner;

	Space* newMove;

	// Map* map;

public:
	Space(); // Default constructor
	Space(std::string nameIn, std::string weaponIn);

	void setTop(Space* roomIn);
	void setBottom(Space* roomIn);
	void setLeft(Space* roomIn);
	void setRight(Space* roomIn);
	void setCorner(Space* roomIn);

	std::string getName() const;
	std::string getWeapon() const;

	char makeMove() const;
	std::string moveValidation() const;

	Space* getTop();
	Space* getBottom();
	Space* getLeft();
	Space* getRight();
	Space* getCorner();

	void roomWelcome() const;

	virtual std::string action();
	virtual ~Space() = default; // Default destructor

	int intValidation(int min, int max);
};


#endif //SPACE_HPP
