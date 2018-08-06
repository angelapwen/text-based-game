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
private:
	bool knife;
	bool rope;
	bool revolver;
	bool wrench;
	bool candlestick;
	bool pipe;

	int totalWeapons;

public:
	Satchel();
	void addWeapon(std::string weapon);

	bool getKnife() const {
		return knife;
	}

	bool getRope() const {
		return rope;
	}

	bool getRevolver() const {
		return revolver;
	}

	bool getWrench() const {
		return wrench;
	}

	bool getCandlestick() const {
		return candlestick;
	}

	bool getPipe() const{
		return pipe;
	}

	int getTotalWeapons() const;

	void printWeapons() const;

};


#endif //SATCHEL_HPP
