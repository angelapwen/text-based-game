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

	bool getKnife() const override{
		return knife;
	}

	bool getRope() const override {
		return rope;
	}

	bool getRevolver() const override {
		return revolver;
	}

	bool getWrench() const override {
		return wrench;
	}

	bool getCandlestick() const override {
		return candlestick;
	}

	bool getPipe() const override{
		return pipe;
	}

	int getNumUniqueWeapons() const override;

	void printWeapons() const override;

};


#endif //BASICSATCHEL_HPP
