/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: game.cpp is the Game class implementation file. It implements a
 * Class that is composed of a Map pointer, a Satchel pointer, and various
 * Space pointers. It runs the game loop, allowing the user to pick a
 * Satchel, move throughout the board, and commit the murder.
*******************************************************************************/

#include "game.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cin;

// Total number of moves the player is allowed before the game ends
int maxMoves = 30;

/*******************************************************************************
The Game class default and only constructor initializes the member
 variables steps to 0 and murder to false. It also creates a Map object
 with the Map pointer member variable, and sets the satchel member variable
 to nullptr. It then constructs all nine Space pointers for each room, and
 links the rooms to one another. Finally, it sets the Space pointer
 current, indicating the player's current location, to the library.
*******************************************************************************/
Game::Game() {
	satchel = nullptr; // Satchel will be allocated later
	map = new Map(); // Construct map immediately
	steps = 0;
	murder = discovery = false;

	// Allocate memory for and construct all rooms
	study = new Quiet("study","candlestick","a book of meditation");
	library = new Quiet("library", "rope", "a box of sleeping pills");
	conservatory = new Quiet("conservatory", "knife", "a pair of earmuffs");
	billiards = new Entertain("billiard room", "pipe", "a game of darts");
	ballroom = new Entertain("ballroom", "rope", "a record player");
	hall = new Entertain("hall", "wrench", "a doorbell");
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

	character = ' ';
	current = nullptr; // Location of start depends on character choice

	// Set location of murder to a random room
	int murderLocation = (rand() % 9) + 1;
	switch (murderLocation) {
		case 1: {
			murderRoom = "study";
			break;
		}
		case 2: {
			murderRoom = "hall";
			break;
		}
		case 3: {
			murderRoom = "lounge";
			break;
		}
		case 4: {
			murderRoom = "dining room";
			break;
		}
		case 5: {
			murderRoom = "kitchen";
			break;
		}
		case 6: {
			murderRoom = "ballroom";
			break;
		}
		case 7: {
			murderRoom = "conservatory";
			break;
		}
		case 8: {
			murderRoom = "billiard room";
			break;
		}
		case 9: {
			murderRoom = "library";
			break;
		}
		default: {
			murderRoom = " ";
			break;
		}
	}
}
/*******************************************************************************
Game::startGame() is a void function without parameters that runs the majority
 of the game loop. It allows the player to move to new rooms, checks if the
 murder can be committed, and displays the exit messages depending on
 whether the player has won, quit the game, or lost.
*******************************************************************************/
void Game::startGame() {
	welcomeMenu();

	characterChoice();
	satchelChoice(); // Construct appropriate satchel

	string weapon;
	bool exit = false;

	cout <<
	     "********************************************************************************"
	     << endl;
	// If character is Miss Scarlet, add revolver to Satchel
	if (character == 's') {
		cout << "Hello, Miss Scarlet.";
		satchel->addWeapon("revolver");
	}

		// If character is Colonel Mustard, increment Satchel capacity
	else if (character == 'm') {
		cout << "Hello, Colonel Mustard." << endl;
		satchel->addCapacity();
	}

		// If character is Mrs. White, turn switch on corner access
	else if (character == 'w') {
		cout << "Hello, Mrs. White." << endl;
		cout << "Mr. Boddy wouldn't report his own maid to the police for being"
			 " on his Estate." << endl;
	}

		// If character is Mr. Green, display room with escape door
	else if (character == 'g') {
		cout << "Hello, Mr. Green." << endl;
		cout << "Thank you for your generous donation to Hydra." << endl;
		cout << "The room you must commit the murder in is the " << murderRoom
		     << "." << endl;
	}

		// If character is Mrs. Peacock, multiply the number of total moves
	else if (character == 'p') {
		cout << "Hello, Mrs. Peacock." << endl;
		maxMoves *= 1.25;
		cout << "Your new number of maximum moves in the estate is " <<
		     maxMoves << "." << endl;
	}

	else {
		cout << "Welcome, Professor Plum." << endl;
		current->setCornerAccess('y');
		cout << "You will be able to access the corner passageways throughout "
		        "the game." << endl;
	}

	cout << "The Boddy Estate butler greets you at the entrance." << endl;
	cout << "\nPress enter to begin searching the Estate for weapons." << endl;
	getchar();

	// Repeat these steps while the murder has not been committed, the user
	// has not elected to exit, step count is below max, and random
	// discovery event has not occurred
	while (steps < maxMoves && !murder && !exit && !discovery) {
		// Increment and print the step number
		steps++;

		cout <<
		     "********************************************************************************"
		     << endl;
		cout << "You are on Move #" << steps << "." << endl;

		// Move player to correct place and print board
		updateMap();
		map->printBoard();
		map->printKey();

		// Check if player has enough weapons and is in the appropriate room
		if ((satchel->getNumUniqueWeapons()) > 3 &&
		    current->getName() == murderRoom) {
			current->roomWelcome();
			commitMurder();
		}

		// If murder has not been committed, move forward with room action
		if (!murder) {
			current->roomWelcome();

			// Chance 1 in 9 that character drops their satchel
			int emptyChance = (rand() % 9) + 1;
			switch (emptyChance) {
				case 1: {
					satchel->clearContents();
					break;
				}
				default:
					break;
			}

			// Store the weapon picked up (if any) from action method
			weapon = current->action();

			// Add weapon (if applicable) to satchel
			if (weapon != "none") {
				satchel->addWeapon(weapon);
			}

			// Check again if player has enough weapons and is in the correct room
			if ((satchel->getNumUniqueWeapons()) > 3 && current->getName() ==
			                                            murderRoom) {
				commitMurder();
			}
		}

		// If murder has not been committed at this stage, chance in 1 of 30
		// that player is discovered by Boddy before moving.
		if (!murder) {
			int discoveryChance = (rand() % 30) + 1;

			switch (discoveryChance) {
				case 1: {
					// Turn discovery on if character is not Mrs. White
					if (character != 'w') {
						discovery = true;
					}
					break;
				}
				default:
					break;
			}

			// If discovery did not occur, move character to next room
			if (!discovery) {
				cout << "\nIt is time to move to another room." << endl;

				// If character is Plum, set corner access on
				if (character == 'o') {
					current->setCornerAccess('y');
				}
					// Else if character is not Mrs. White but has wrench, set corner
					// access on
				else if (satchel->getWrench()) {
					cout
							<< "\nHello from Hydra. We noticed that you have a wrench in";
					cout << " your satchel. While you\nhave a wrench, you may access "
							   "the secret corner passageways in the Boddy Estate."
							<< endl << endl;
					current->setCornerAccess('y');
				}
					// Else turn corner access off
				else {
					current->setCornerAccess('n');
				}

				// Display options for the user to move and get user choice
				char move = current->makeMove();

				// Depending on char returned, point current to new room or exit
				switch (move) {
					case 't':
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
	}

	cout <<
	     "\n********************************************************************************"
	     << endl;

	// If murder has been committed, display congratulations
	if (murder) {
		cout << "Congratulations, professor! You have completed your mission in "
			  << steps << " moves." << endl;
		cout << "We have activated a secret escape in the " << murderRoom <<
					"." << endl;
		cout << "Open the door and step in to your freedom." << endl;
		cout << "\n\nYour next mission will be:" << endl;
		cout << "DEFEND YOUR INNOCENCE. FRAME ANOTHER GUEST FOR MR. BODDY'S "
		        "MURDER." << endl;
		cout << "The others will be here soon..." << endl;
		cout << "\n\nRemember: Cut off a limb, and two more shall take its "
		        "place." << endl;
	}

	// Else if user reached max number of steps, display exit message
	else if (steps >= maxMoves) {
		cout << "Unfortunately, you exceeded the total number of moves to "
		        "complete your mission." << endl;
		cout << "We have removed you from Mr. Boddy's estate." << endl;
		cout << "\nNot everyone is meant for the greatness of HYDRA." << endl;
		cout << "The Hydra selection process is a dangerous one." << endl;
		cout << "Those who do not successfully complete it are liabilities to "
		        "our organization." << endl;
		cout << "Perhaps you may serve Hydra in your next life." << endl;
		cout << "\n\n\nDo you have any last words before we begin?" << endl;
	}

	// Else player has been discovered, display exit message
	else if (discovery) {
		cout << "Before you decide on your next move, Mr. Boddy walks into the " <<
		     current->getName() << "." << endl;
		cout << "You have been discovered after " << steps << " moves!!" << endl;
		cout << "\nMR. BODDY: \"You aren't supposed to be in here.\"" << endl;
		cout << "MR. BODDY: \"Are you trying to steal my things??\"" << endl;
		cout << "MR. BODDY: \"I expected better from you. I'd better call the "
		        "police. \"" << endl;
		cout << "\nThe police have escorted you from Mr. Boddy's estate." << endl;
		cout << "They do not find any evidence of stolen items on you and you "
			 "are released." << endl;
		cout << "\nYou have failed to complete your mission." << endl;
		cout << "Not everyone is meant for the greatness of HYDRA." << endl;
		cout << "The HYDRA selection process is a dangerous one." << endl;
		cout << "Those who do not successfully complete it are liabilities to "
		        "our organization." << endl;
		cout << "Perhaps you may serve Hydra in your next life." << endl;
		cout << "\n\n\nDo you have any last words before we begin?" << endl;
	}

	// Else if user has elected to exit, display exit message
	else {
		cout << "You have chosen to use the Emergency Exit after " << steps <<
		     " steps." << endl;
		cout << "You decided to leave your mission incomplete." << endl;
		cout << "\nNot everyone is meant for the greatness of HYDRA." << endl;
		cout << "The HYDRA selection process is a dangerous one." << endl;
		cout << "Those who do not successfully complete it are liabilities to "
		        "our organization." << endl;
		cout << "Perhaps you may serve Hydra in your next life." << endl;
		cout << "\n\n\nDo you have any last words before we begin?" << endl;
	}
	cout <<
	     "********************************************************************************"
	     << endl;
}
/*******************************************************************************
Game::welcomeMenu() is a void function without parameters. It displays the game
 title and tells the player about their goal.
*******************************************************************************/
void Game::welcomeMenu() const {
	cout <<
	     "\n********************************************************************************"
	     << endl;

	cout << "\n\t\t\t\t\t\t\t   Clue: The Prequel" << endl;
	cout <<
	     "\n********************************************************************************"
	     << endl;
	cout << "\nGood evening, Professor Plum." << endl;
	cout << "We have received your application to join us at Hydra." << endl;
	cout << "We were pleased to hear of your interest, as we have been ";
	cout << "watching closely over\nyour work in the past few years." << endl;
	cout << "\nAs you know, we are an ancient Brotherhood." << endl;
	cout << "All of our applicants are subject to a series of tests and "
	        "missions to test your\ntrue dedication to our organization.";
	cout << " Tonight will be your first mission." << endl;
	cout << "\nMr. John Boddy has invited you to his 30th birthday party." <<
	     endl;
	cout << "You have access to the Boddy estate prior to the party." << endl;
	cout << "\nYour mission: " ;
	cout << "MURDER MR. JOHN BODDY BEFORE THE OTHER GUESTS ARRIVE." << endl;
	cout << "\nTo complete your mission, you will need to:" << endl;
	cout << "1. Walk around the estate and interact with the rooms." << endl;
	cout << "2. We will decide whether or not to teleport weapons to you based"
	        " off of your\nactions.";
	cout << " If you come across a weapon, you must attempt to put it in your\n"
	        "satchel. You may not leave weapons in the rooms for witnesses to "
	        "find." << endl;
	cout << "3. Once you have 4 unique weapons in your satchel, you must "
	     << "find the correct\nroom in which to commit the murder.";
	cout << " We have set up this room with a secret\nescape so you may leave "
	        "the scene of the crime undetected." << endl;

	cout << "\nOne more thing: as you know, the Boddy Estate is vast." << endl;
	cout << "It will take time for you to move between rooms to complete the "
	        "mission." << endl;
	cout << "You will only have time for " << maxMoves << " moves between "
	       "rooms to complete your mission\nbefore the dinner party begins." <<
	     endl;

	cout << "\nAdditionally, there is a chance that Mr. Boddy will discover you "
			"sneaking\naround his Estate.";
	cout << " Mr. Boddy is a suspicious man, and should this happen, you\nwill "
			"be reported to the police immediately." << endl;

	cout << "\nTo assist you in completing your mission more quickly, we have "
	        "found a way to\naccess the secret passageways between corner rooms in"
	        " the Boddy Estate. When\nyour satchel contains the wrench weapon, you"
	        " may use this special wrench to\nopen the door to the underground "
	        "tunnels that Mr. Boddy keeps locked up." << endl;

	cout << "\nFinally, you may choose to use the Emergency Exit at any point "
	        "in the game, but\nthis means you will not have completed your "
			"mission and have failed Hydra." << endl;
	cout << "\nRemember: if a head is cut off, two more shall take its place." <<
	     endl;
	cout << "Hail, Hydra!" << endl;
	cout << "\nPress enter to accept your mission."	<< endl;
	getchar();
}

/*******************************************************************************
Game::characterChoice() is a void function without parameters. It displays
 the six options of characters the player may pick, along with the special
 features of each. It then sets the character member variable and initializes
 the current member variable to the appropriate room.
*******************************************************************************/
void Game::characterChoice() {
	cout <<
	     "********************************************************************************"
	     << endl;
	cout << "You may pick a disguise before you enter." << endl;
	cout << "\nYou have the option of disguising yourself with Hydra technology "
			"as "
			"one of\nthe other guests while you complete your mission. ";
	cout << "Each disguise will come with a\nspecial feature. ";
	cout << "Each character also begins in a different room in the estate." <<
	     endl;
	cout << "If you continue as yourself, you will also receive a special "
			"feature." << endl;
	cout << "\nThe disguises we have available are:" << endl;
	cout << "\n- Miss Scarlet is a femme fetale." << endl;
	cout << "Special Feature: Miss Scarlet has charmed a Hydra employee to let"
			" her satchel\nbegin with a revolver instead of empty." << endl;
	cout << "Starting Location: Hall." << endl;
	cout << "\n- Colonel Mustard is a dangerous hunter." << endl;
	cout << "Special Feature: Colonel Mustard's satchel's capacity is 1 more "
			"than the\ndefault number."	<< endl;
	cout << "Starting Location: Dining Room." << endl;
	cout << "\n- Mrs. White is the disgruntled servant of the estate." << endl;
	cout << "Special Feature: Mrs. White will never be randomly discovered by "
			"Mr. Boddy, as\nshe is allowed to be in the Estate at any time."	<<
	     endl;
	cout << "Starting Location: Kitchen." << endl;
	cout << "\n- Mr. Green is a mobster." << endl;
	cout << "Special Feature: Mr. Green has paid one of the Hydra employees "
			"off to find out\nwhich room the secret escape is in before the game "
			"begins." << endl;
	cout << "Starting Location: Ballroom." << endl;
	cout << "\n- Mrs. Peacock is a grand dame." << endl;
	cout << "Special Feature: Due to her age, Mrs. Peacock receives 1.25x the "
			"number of\nmaximum moves before the dinner begins." << endl;
	cout << "Starting Location: Conservatory." << endl;
	cout << "\n- Complete your mission as Professor Plum." << endl;
	cout << "Special Feature: you receive a key to access all the "
			"corner passageways\nthroughout the game, regardless of if you have "
			"the wrench." << endl;
	cout << "Starting Location: Library." << endl;
	cout << "\nHere is a map of the Estate:" << endl;
	map->printBoard();
	cout << "\n\tCHARACTER MENU" << endl;
	cout << "1. Miss Scarlet" << endl;
	cout << "2. Colonel Mustard" << endl;
	cout << "3. Mrs. White" << endl;
	cout << "4. Mr. Green" << endl;
	cout << "5. Mrs. Peacock" << endl;
	cout << "6. Turn down the disguise-- remain as Professor Plum." << endl;
	cout << "Make your choice: ";

	int characterChoice = intValidation(1,6);

	// Initialize character variable depending on choice
	switch (characterChoice) {
		case 1: {
			character = 's'; // For Scarlet
			current = hall;
			map->placeHall();
			break;
		}
		case 2: {
			character = 'm'; // For Mustard
			current = dining;
			map->placeDining();
			break;
		}
		case 3: {
			character = 'w'; // For White
			current = kitchen;
			map->placeKitchen();
			break;
		}
		case 4: {
			character = 'g'; // For Green
			current = ballroom;
			map->placeBallroom();
			break;
		}
		case 5: {
			character = 'p'; // For Peacock
			current = conservatory;
			map->placeConservatory();
			break;
		}
			case 6: {
			character = 'o'; // For original, Plum
			current = library;
			map->placeLibrary();
			break;
		}
		default:
			break;
	}

	cout << "Thank you, your choice has been noted." << endl;
	cout << "\nPress enter to continue." << endl;
	getchar();
}

/*******************************************************************************
Game::satchelChoice() is a void function without parameters. It displays the
 three options of satchels the player may pick, along with the benefits of
 each. Depending on the user choice, it constructs the appropriate object.
*******************************************************************************/
void Game::satchelChoice() {
	cout <<
	     "********************************************************************************"
	     << endl;
	cout << "It is time to choose your satchel." << endl;
	cout << "Should you succeed in your missions, your placement in Hydra will"
			" depend upon\nyour demonstrated abilities and desire to challenge "
			"yourself."	<< endl;
	cout << "\n- The Bronze Satchel will provide you with the highest chance "
			"of success." << endl;
	cout << "It will only allow weapons that it does not already contain to be "
			"placed inside." << endl;
	cout << "Its capacity is 4 weapons. Once you fill it, you may proceed "
			"directly to find\nthe room with the secret escape." << endl;
	cout << "\n- The Silver Satchel will provide you with a moderate "
			"chance of success." << endl;
	cout << "It has a capacity of 5 weapons." << endl;
	cout << "It will allow you to add repeated weapons into the bag." << endl;
	cout << "Once you reach capacity and attempt to add more weapons, it will "
			"choose a random\nweapon to drop before adding the new weapon." <<
	     endl;
	cout << "With this satchel, you will need to keep track of its contents so"
			" that you have\n4 unique weapons to be able to commit the murder."
	<< endl;
	cout << "\n- The Gold Satchel will provide you with the lowest chance of "
			"success." << endl;
	cout << "It has a capacity of 4 weapons, and allows repeated weapons." <<
	     endl;
	cout << "Once you reach capacity and attempt to add more weapons, it will "
			"drop the first\nweapon in it (in a First In First Out format)." <<
	     endl;
	cout << "You will need to keep track of its contents and which rooms "
	     << "contain which\nweapons in order to succeed with the Gold Satchel."
			<< endl;
	cout << "\n\tSATCHEL MENU" << endl;
	cout << "1. Bronze Satchel" << endl;
	cout << "2. Silver Satchel" << endl;
	cout << "3. Gold Satchel" << endl;
	cout << "Make your choice: ";

	int satchelChoice = intValidation(1,3);

	// Construct the appropriate satchel based off the user's choice.
	switch (satchelChoice) {
		case 1: {
			satchel = new BasicSatchel;
			cout << "\nYou have selected the Bronze Satchel." << endl;
			cout << "We hope that next time, you will challenge yourself further."
			  << endl;
			break;
		}
		case 2: {
			satchel = new VectorSatchel;
			cout << "\nYou have selected the Silver Satchel." << endl;
			cout << "A safe choice. We will be watching you closely to assess "
			  "your talent." << endl;
			break;
		}
		case 3: {
			satchel = new QueueSatchel;
			cout << "\nYou have selected the Gold Satchel." << endl;
			cout << "You have demonstrated your ambition. Should you succeed, you "
			  "will be rewarded\nbeyond your wildest dreams." << endl;
		}
		default:
			break;
	}

	cout << "\nPress enter to take your satchel and begin your mission."	<< endl;
	getchar();
}
/*******************************************************************************
Game::intValidation is a function with two int parameters that returns an int
 value. It prompts the user for input and validates the input to be an
 integer between the min and max parameters, and returns the valid value.
*******************************************************************************/
int Game::intValidation(int min, int max) const {
	int input;
	cin >> input;

	// Try again if input is out of range or fails
	while (input < min || input > max || cin.fail()) {
		cout << "Input must be an integer between " << min << " and "
		     << max << "." << endl;
		cout << "Please try again: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> input;
	}

	// Flush buffer after successful input
	cin.clear();
	cin.ignore(256, '\n');

	return input;
}
/*******************************************************************************
Game::updateMap() is a void function without parameters. It is called in the
 beginning of each step to update the map depending on where the player is.
*******************************************************************************/
void Game::updateMap() {
	// Place the user's * on map depending on the new room
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

/*******************************************************************************
Game::commitMurder() is a void function without parameters. It is called only if
 the player is in the murder room and has four or more unique weapons. It
 prints the available weapons and allows the user to pick one of them to
 commit the murder. It sets the murder bool to true.
*******************************************************************************/
void Game::commitMurder() {
	string weaponChoice;

	cout <<
	     "\n********************************************************************************"
	     << endl;
	cout << "Mr. Boddy has entered the " << murderRoom << "." << endl;
	cout << "You have successfully collected at least four unique weapons." <<
	     endl;
	cout << "This is your opportunity to murder him and flee the scene!" << endl;
	cout << "\nPress enter when you are ready." << endl;
	getchar();
	cout << "Which weapon would you like to use to kill Mr. Boddy?" << endl;
	cout << "The contents of your satchel: " << endl;

	// Print weapons in the satchel
	satchel->printWeapons();

	cout << "Type your weapon of choice exactly as printed above." << endl;
	weaponChoice = weaponValidation();

	cout << "\nYou advance towards Mr. Boddy, " << weaponChoice << " in hand."
																				  << endl;
	cout << "He smiles at you. \"";
	if (character == 's') {
		cout << "Miss Scarlet!";
	}
	else if (character == 'm') {
		cout << "Colonel Mustard!";
	}
	else if (character == 'w') {
		cout << "Mrs. White!";
	}
	else if (character == 'g') {
		cout << "Mr. Green!";
	}
	else if (character == 'p') {
		cout << "Mrs. Peacock!";
	}
	else {
		cout << "Professor Plum!";
	}
	cout << " Where did you come from?\"" << endl;
	cout << "You do not hesitate." << endl;
	cout << "After all, Hydra is counting on you." << endl;

	if (weaponChoice == "pipe") {
	cout << "You have murdered Mr. Boddy, with the lead " <<
	     weaponChoice << ", in the " << murderRoom << "." << endl;
	}
	else {
		cout << "You have murdered Mr. Boddy, with the " <<
		     weaponChoice << ", in the " << murderRoom << "." << endl;
	}

	murder = true;

	cout << "\nPress enter to continue." << endl;
	getchar();
}

/*******************************************************************************
Game::weaponValidation() is a function without parameters that returns the
 string of the user's input. It validates that the user has selected one of
 the six weapons in the game, and also that the satchel contains the weapon.
*******************************************************************************/
string Game::weaponValidation() const {
	string input;
	bool hasWeapon = false;

	while (!hasWeapon) {
		cout << "\nMake your choice: ";
		cin >> input;

		// While input is not a valid weapon name, ask user to try again
		while (input != "knife" && input != "revolver" && input != "rope" && input
		       !="wrench" && input != "candlestick" && input != "pipe") {
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
		}
		else if (input == "revolver" && !satchel->getRevolver()) {
			cout << "You do not carry a revolver in your satchel. Try again.";
		}
		else if (input == "rope" && !satchel->getRope()) {
			cout << "You do not carry a rope in your satchel. Try again.";
		}
		else if (input == "wrench" && !satchel->getWrench()) {
			cout << "You do not carry a wrench in your satchel. Try again.";
		}
		else if (input == "candlestick" && !satchel->getCandlestick()) {
			cout << "You do not carry a knife in your satchel. Try again.";
		}
		else if (input == "pipe" && !satchel->getPipe()) {
			cout << "You do not carry a lead pipe in your satchel. Try again.";
		}
			// Else the satchel contains the weapon
		else {
			hasWeapon = true;
		}
	}
	return input;
}

/*******************************************************************************
Game::repeatMenu() is a void function without parameters. It displays the
 options for the user to either play the game again or exit.
*******************************************************************************/
void Game::repeatMenu() const {
	cout << "\n\t PLAY AGAIN?" << endl;
	cout << "1. Try your hand at joining Hydra again." << endl;
	cout << "** Remember: the room with the secret escape changes for each "
			"trial." << endl;
	cout << "2. Exit the program." << endl;
	cout << "Make your choice: " << endl;
}

/*******************************************************************************
Game::~Game is the Game class default destructor. It frees the memory for all
 the dynamically allocated member variables: satchel, map, and all rooms.
*******************************************************************************/
Game::~Game() {
	delete satchel;
	delete map;

	// Free memory for all rooms
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