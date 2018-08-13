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
	unsigned capacity; // Number of weapons satchel can hold
	unsigned numUniqueWeapons;

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
	virtual void printWeapons() const = 0;

	void addCapacity();
	virtual void clearContents();
	virtual int getNumUniqueWeapons();

	// Accessor functions for each bool variable
	bool getKnife() const;
	bool getWrench() const;
	bool getCandlestick() const;
	bool getRope() const;
	bool getPipe() const;
	bool getRevolver() const;

	// Virtual destructor
	virtual ~Satchel();
};


#endif //SATCHEL_HPP
