/*******************************************************************************
 * Program: Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: quiet.hpp is the Quiet class header file. It specifies a Class
 * that inherits publicly from the Space abstract class. The rooms that will
 * be instantiated with this theme are the Study, Library, and Conservatory.
*******************************************************************************/

#ifndef QUIET_HPP
#define QUIET_HPP

#include "space.hpp"

class Quiet : public Space{
private:
	std::string quietItem;

public:
	Quiet();

	Quiet(std::string nameIn, std::string weaponIn, std::string quietIn);

	std::string action() override;
};


#endif //FINAL_QUIET_HPP
