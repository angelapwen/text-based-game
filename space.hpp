/*******************************************************************************
 * Program: Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: space.hpp is the Space Class specification file. It specifies
 * an abstract class Space that Classes Eat, Entertain, and Quiet will
 * publicly inherit from.
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

	bool cornerAccess;

	std::string moveValidation() const;
	int intValidation(int min, int max);

public:
	Space(); // Default constructor
	Space(std::string nameIn, std::string weaponIn);

	void setTop(Space* roomIn);
	void setBottom(Space* roomIn);
	void setLeft(Space* roomIn);
	void setRight(Space* roomIn);
	void setCorner(Space* roomIn);

	std::string getName() const;

	void setCornerAccess (char access);
	char makeMove() const;

	Space* getTop();
	Space* getBottom();
	Space* getLeft();
	Space* getRight();
	Space* getCorner();

	void roomWelcome() const;

	virtual std::string action();

	virtual ~Space() = 0; // Pure virtual destructor
};


#endif //SPACE_HPP
