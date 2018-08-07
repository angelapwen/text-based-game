/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#ifndef BASICSATCHEL_HPP
#define BASICSATCHEL_HPP

#include <string>
#include <iostream>

#include "satchel.hpp"

class basicSatchel : public Satchel {
private:
	bool knife;
	bool rope;
	bool revolver;
	bool wrench;
	bool candlestick;
	bool pipe;

public:
	basicSatchel();
	void addWeapon(std::string weapon) override;

	bool getKnife() const override;
	bool getRope() const override;
	bool getRevolver() const override;
	bool getWrench() const override;
	bool getCandlestick() const override;
	bool getPipe() const override;

	int getNumUniqueWeapons() const override;
	void printWeapons() const override;

};


#endif //BASICSATCHEL_HPP
