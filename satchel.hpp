/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#ifndef SATCHEL_HPP
#define SATCHEL_HPP

#include <string>

class Satchel {
protected:
	int capacity;
	int numTotalWeapons;
	int numUniqueWeapons;
public:
	Satchel();

	explicit Satchel(int capacityIn);

	virtual void addWeapon(std::string weapon) = 0;

	// virtual int getNumTotalWeapons() const = 0;
	virtual int getNumUniqueWeapons() const = 0;

	virtual void printWeapons() const = 0;

	virtual bool getKnife() const = 0;
	virtual bool getWrench() const = 0;
	virtual bool getCandlestick() const = 0;
	virtual bool getRope() const = 0;
	virtual bool getPipe() const = 0;
	virtual bool getRevolver() const = 0;

	virtual ~Satchel() = default;

};


#endif //SATCHEL_HPP
