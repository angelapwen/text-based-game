/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description:
*******************************************************************************/

#include "game.hpp"

#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int TOTAL_MOVES = 100;

Game::Game() {
	satchel = new Satchel();
	map = new Map();
	steps = 0;
	murder = false;

	// Allocate memory for and construct all rooms
	study = new Quiet("study","candlestick","a book of meditation");
	library = new Quiet("library", "rope", "a box of sleeping pills");
	conservatory = new Quiet("conservatory", "knife", "a pair of earmuffs");
	billiards = new Entertain("billiard room", "lead pipe", "darts");
	ballroom = new Entertain("ballroom", "rope", "record player");
	hall = new Entertain("hall", "wrench", "doorbell");
	kitchen = new Eat("kitchen", "knife", "an apple");
	dining = new Eat("dining room", "revolver", "a pumpkin pastry");
	lounge = new Eat("lounge", "candlestick", "a block of cheese");

	// Link all rooms
	study->setCorner(kitchen);
	study->setRight(hall);
	study->setBottom(library);

	library->setTop(study);
	library->setBottom(billiards);

	billiards->setTop(library);
	billiards->setBottom(conservatory);

	conservatory->setTop(billiards);
	conservatory->setRight(ballroom);
	conservatory->setCorner(lounge);

	ballroom->setLeft(conservatory);
	ballroom->setRight(kitchen);

	kitchen->setLeft(ballroom);
	kitchen->setTop(dining);
	kitchen->setCorner(study);

	dining->setBottom(kitchen);
	dining->setTop(lounge);

	lounge->setBottom(dining);
	lounge->setLeft(hall);
	lounge->setCorner(conservatory);

	hall->setRight(lounge);
	hall->setLeft(study);

	current = library; // Professor Plum starts at the Library
}

void Game::welcomeMenu() const {
	cout <<
	     "\n********************************************************************************"
	     << endl;

	cout << "\n\t\t\t\t\t\t\t   Clue: The Prequel" << endl;
	cout <<
	     "\n********************************************************************************"
	     << endl;
	cout << "\nGood evening, Professor Plum." << endl;
	cout << "We have received your application to join us at HYDRA." << endl;
	cout << "We were pleased to hear of your interest, as we have been ";
	cout << "watching closely over\nyour work in the past few years." << endl;
	cout << "\nAs you know, we are an ancient Brotherhood." << endl;
	cout << "All of our applicants are subject to a series of tests and "
			"missions to test your\ntrue dedication to our organization.";
	cout << " Tonight will be your first mission." << endl;
	cout << "\nThe brother of your late wife, Mr. John Boddy, has invited you "
			"to his 30th\nbirthday party.";
	cout << " As a member of the family, you have access to the Boddy estate "
			"\nprior to the party." << endl;
	cout << "\nYour mission: " ;
	cout << "MURDER MR. JOHN BODDY BEFORE THE OTHER GUESTS ARRIVE." << endl;
	cout << "\nTo complete your mision, you will need to:" << endl;
	cout << "1. Walk around the mansion and interact with the rooms.";
	cout << " You begin in the library." << endl;
	cout << "2. If your interactions go well, you will pick up weapons for "
			"your satchel." << endl;
	cout << "Your satchel will only fit 5 weapons." << endl;
	cout << "3. Once you have 4 unique weapons in your satchel, you must "
			<< "find the appropriate\nroom in which to commit the murder.";
	cout << " We have set up this room with a secret\nescape so you may leave "
			"the scene of the crime undetected." << endl;

	cout << "\nOne more thing: as you know, the Boddy Estate is vast." << endl;
	cout << "It will take time for you to move between rooms to complete the "
			"mission." << endl;
	cout << "You will only have time for " << TOTAL_MOVES << " moves between "
			"rooms to complete your mission\nbefore the dinner party begins." <<
	     endl;

	cout << "\nYou may choose to use the Emergency Exit at any point in the "
			"game, although\nthis means you will not have completed your mission"
			" and have failed HYDRA." << endl;
	cout << "\nRemember: if a head is cut off, two more shall take its place." <<
	     endl;
	cout << "Hail, Hydra!" << endl;
}

void Game::startGame() {
	string weapon;
	bool exit = false;

	// Repeat these steps while the murder has not been committed, the user
			// has not elected to exit, and step count is below max
	while (steps < TOTAL_MOVES && !murder && !exit) {
		// Increment and print the step number
		steps++;

		cout <<
		     "\n********************************************************************************"
		     << endl;
		cout << "You are on Move #" << steps << "." << endl;

		// Move player to correct place and print board
		updateBoard();
		map->printBoard();

		// First check if player has enough weapons and is in the Billiards Room
		if ((satchel->getTotalWeapons()) > 3 && current->getName() == "billiard "
																				  "room") {
			current->roomWelcome();
			commitMurder();
		}

		// If murder has not been committed, move forward with room action
		if (!murder) {
			current->roomWelcome();

			// Store the weapon picked up (if any) from action method
			weapon = current->action();

			// Add weapon (if applicable) to satchel
			satchel->addWeapon(weapon);

			// Check again if player has enough weapons and is in Billiards Room
			if ((satchel->getTotalWeapons()) > 3 && current->getName() ==
			                                      "billiard room") {
				commitMurder();
			}
		}

		// If murder has not been committed at this stage, display move menu
		if (!murder) {
			char move = current->makeMove();

			// Depending on char returned, point current to new room or exit
			switch (move) {
				case 't':

					// current = current->top; // Cannot access because inaccessible

					current = current->getTop();
					break;
				case 'b':
					current = current->getBottom();
					break;
				case 'l':
					current = current->getLeft();
					break;
				case 'r':
					current = current->getRight();
					break;
				case 'c':
					current = current->getCorner();
					break;
				case 'e':
					exit = true;
					break;
				default:
					break;
			}

		}
	}

	// If murder has been committed, display congratulations and allow user to
	// escape
	if (murder) {
		cout <<
		     "\n********************************************************************************"
		     << endl;
		cout << "Congratulations, professor! You have completed your mission." <<
		     endl;
		cout << "It took you " << steps << " steps to complete your mission." <<
		     endl;
		cout << "We have activated a secret escape in the grandfather clock\n";
		cout << "across from you in the billiard room." << endl;
		cout << "Open the door and step in to your freedom." << endl;
		cout << "\n\nYour second mission:" << endl;
		cout << "DEFEND YOUR INNOCENCE. FRAME ANOTHER GUEST FOR MR. BODDY'S "
			 "murder." << endl;
		cout << "The others will be here soon..." << endl;
		cout << "\n\nRemember: Cut off a limb, and two more shall take its "
			 "place.";
		cout <<
		     "********************************************************************************"
		     << endl;
	}

		// Else if user reached max number of steps, tell user sorry and maybe they
		// will be a better murderer next time
	else if (steps >= TOTAL_MOVES) {
		cout <<
		     "\n********************************************************************************"
		     << endl;
		cout << "Unfortunately, you exceeded the total number of moves to "
				  "complete your mission." << endl;
		cout << "We have removed you from Mr. Boddy's mansion." << endl;
		cout << "\nNot everyone is meant for the greatness of HYDRA." << endl;
		cout << "The HYDRA selection process is a dangerous one." << endl;
		cout << "Those who do not successfully complete it are liabilities to "
			 "our organization." << endl;
		cout << "Perhaps you may serve HYDRA in your next life." << endl;
		cout << "\n\n\nDo you have any last words before we begin?" << endl;
		cout <<
		     "********************************************************************************"
		     << endl;
	 }

	// Else user has elected to exit, thank user for playing
	else {
		cout <<
		     "\n********************************************************************************"
		     << endl;
		cout << "You have chosen to use the Emergency Exit after " << steps <<
		     " steps." << endl;
		cout << "You chose not to complete your mission." << endl;
		cout << "\nNot everyone is meant for the greatness of HYDRA." << endl;
		cout << "The HYDRA selection process is a dangerous one." << endl;
		cout << "Those who do not successfully complete it are liabilities to "
		        "our organization." << endl;
		cout << "Perhaps you may serve HYDRA in your next life." << endl;
		cout << "\n\n\nDo you have any last words before we begin?" << endl;
		cout <<
		     "********************************************************************************"
		     << endl;
	}
}

void Game::updateBoard() {
	if (current->getName() == "study") {
		map->placeStudy();
	}
	else if (current->getName() == "library") {
		map->placeLibrary();
	}
	else if (current->getName() == "conservatory") {
		map->placeConservatory();
	}
	else if (current->getName() == "billiard room") {
		map->placeBilliards();
	}
	else if (current->getName() == "dining room") {
		map->placeDining();
	}
	else if (current->getName() == "ballroom") {
		map->placeBallroom();
	}
	else if (current->getName() == "lounge") {
		map->placeLounge();
	}
	else if (current->getName() == "kitchen") {
		map->placeKitchen();
	}
	else if (current->getName() == "hall") {
		map->placeHall();
	}
	else {
		cout << "Invalid room name." << endl;
	}
}

void Game::commitMurder() {
	string weaponChoice;

	cout << "Mr. Boddy has entered the billiard room." << endl;
	cout << "You have successfully collected at least four unique weapons." <<
	     endl;
	cout << "This is your opportunity to murder him and flee the scene!" << endl;
	cout << "Which weapon would you like to use to kill Mr. Boddy?" << endl;
	cout << "Your options are: " << endl;

	satchel->printWeapons();

	cout << "Type your weapon of choice exactly as printed above." << endl;
	weaponChoice = weaponValidation();

	cout << "\nYou advance towards Mr. Boddy, " << weaponChoice << " in hand."
																				  << endl;
	cout << "He looks up at the last moment -- but it's too late." << endl;

	cout << "You have successfully murdered Mr. Boddy, with the " << weaponChoice
	      << ",\nin the Billiard Room." << endl;

	murder = true;
}

/*******************************************************************************

 *******************************************************************************/
string Game::weaponValidation() const {
	string input;
	bool hasWeapon = false;

	while (!hasWeapon) {
		cout << "\nMake your choice: ";
		getline(cin, input);

		// While input is not a valid weapon name, ask user to try again
		while (input != "knife" && input != "revolver" && input != "rope" && input
		       !="wrench" && input != "candlestick" && input != "lead pipe") {
			cout << "Input must be a valid weapon name." << endl;
			cout << "Please try again: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> input;
		}

		cin.clear();
		cin.ignore(256, '\n');

		// If input is a valid weapon, check to see if satchel contains this weapon
		if (input == "knife" && !satchel->getKnife()) {
			cout << "You do not carry a knife in your satchel. Try again.";
		} else if (input == "revolver" && !satchel->getRevolver()) {
			cout << "You do not carry a revolver in your satchel. Try again.";
		} else if (input == "rope" && !satchel->getRope()) {
			cout << "You do not carry a rope in your satchel. Try again.";
		} else if (input == "wrench" && !satchel->getWrench()) {
			cout << "You do not carry a wrench in your satchel. Try again.";
		} else if (input == "candlestick" && !satchel->getCandlestick()) {
			cout << "You do not carry a knife in your satchel. Try again.";
		} else if (input == "lead pipe" && !satchel->getPipe()) {
			cout << "You do not carry a lead pipe in your satchel. Try again.";
		}
			// Else the satchel contains the weapon
		else {
			hasWeapon = true;
		}
	}
	return input;
}

void Game::repeatMenu() const {
	cout << "\n\n\n PLAY AGAIN?" << endl;
	cout << "1. Play a new game." << endl;
	cout << "2. Exit the program." << endl;
	cout << "Make your choice: " << endl;
}

Game::~Game() {
	delete satchel;
	delete map;

	// Delete all rooms
	delete study;
	delete library;
	delete billiards;
	delete conservatory;
	delete ballroom;
	delete kitchen;
	delete dining;
	delete lounge;
	delete hall;

}



