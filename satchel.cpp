/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#include "satchel.hpp"

using std::cout;
using std::endl;

Satchel::Satchel() {
	capacity = numUniqueWeapons = -1;
	knife = rope = wrench = revolver = candlestick = pipe = false;
}

Satchel::Satchel(int capacityIn) {
	capacity = capacityIn;
	numUniqueWeapons = 0;
	knife = rope = wrench = revolver = candlestick = pipe = false;
}

bool Satchel::getCandlestick() const {
	return candlestick;
}

bool Satchel::getRope() const {
	return rope;
}

bool Satchel::getRevolver() const {
	return revolver;
}

bool Satchel::getPipe() const {
	return pipe;
}

bool Satchel::getKnife() const {
	return knife;
}

bool Satchel::getWrench() const {
	return wrench;
}