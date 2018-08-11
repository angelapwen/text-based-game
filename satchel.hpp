/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: satchel.hpp is the header file for the Satchel abstract class.
 * The basicSatchel, queueSatchel, and vectorSatchel classes will inherit
 * from this class.
*******************************************************************************/

#ifndef SATCHEL_HPP
#define SATCHEL_HPP

#include <string>
#include <iostream>

class Satchel {
protected:
	int capacity; // Number of weapons satchel can hold
	int numUniqueWeapons;

	// Bool variables indicating whether the satchel contains this weapon or not
	bool knife;
	bool rope;
	bool revolver;
	bool wrench;
	bool candlestick;
	bool pipe;

public:
	Satchel();
	explicit Satchel(int capacityIn); // 1-parameter constructor

	// Pure virtual functions that will be overridden
	virtual void addWeapon(std::string weapon) = 0;
	virtual int getNumUniqueWeapons() = 0;
	virtual void printWeapons() const = 0;

	// Virtual accessor functions for each bool variable
	virtual bool getKnife() const;
	virtual bool getWrench() const;
	virtual bool getCandlestick() const;
	virtual bool getRope() const;
	virtual bool getPipe() const;
	virtual bool getRevolver() const;

	// Virtual destructor
	virtual ~Satchel() = default;

};


#endif //SATCHEL_HPP
