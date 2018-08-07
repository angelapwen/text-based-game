/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#ifndef SATCHEL_HPP
#define SATCHEL_HPP

#include <string>
#include <iostream>

class Satchel {
protected:
	int capacity;
	int numTotalWeapons;
	int numUniqueWeapons;

	bool knife;
	bool rope;
	bool revolver;
	bool wrench;
	bool candlestick;
	bool pipe;

public:
	Satchel();

	explicit Satchel(int capacityIn);

	virtual void addWeapon(std::string weapon) = 0;

	// virtual int getNumTotalWeapons() const = 0;
	virtual int getNumUniqueWeapons() = 0;

	virtual void printWeapons() const = 0;

	virtual bool getKnife() const;
	virtual bool getWrench() const;
	virtual bool getCandlestick() const;
	virtual bool getRope() const;
	virtual bool getPipe() const;
	virtual bool getRevolver() const;

	virtual ~Satchel() = default;

};


#endif //SATCHEL_HPP
