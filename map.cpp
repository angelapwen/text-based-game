/*******************************************************************************
 * Program: CS 162 Final Project -- Clue: The Prequel
 * Name: Angela Wen
 * Date: August 6, 2018
 * Description: map.cpp is the Map class implementation file. It implements a
 * Map class that represents the floor plan of the Boddy Estate. It includes
 * a constructor, a method to clear the player's previous location, methods
 * to place the player in each room, and a method to print the board.
*******************************************************************************/

#include "map.hpp"

using std::string;

/* The Map class constructor fills in the static 2-D array of the board
 * row-by-row, with strings representing each row.  */
Map::Map() {
	// Create strings representing each row of the board
	string row24 = "|-------------------------------------------------------|\n";
	string row23 = "|              |      |           |      |              |\n";
	string row22 = "|    STUDY     |      |           |      |              |\n";
	string row21 = "|              |      |           |      |    LOUNGE    |\n";
	string row20 = "|--------------|      |    HALL   |      |              |\n";
	string row19 = "|                     |           |      |--------------|\n";
	string row18 = "|-----------|_        |           |                     |\n";
	string row17 = "|             |       |-----------|                     |\n";
	string row16 = "|  LIBRARY    |                        |----------------|\n";
	string row15 = "|             |                        |                |\n";
	string row14 = "|            _|                        |                |\n";
	string row13 = "|-----------|        ~~~~~~~~~~~~      |                |\n";
	string row12 = "|                    BODDY ESTATE      |     DINING     |\n";
	string row11 = "|------------|        FLOOR PLAN       |      ROOM      |\n";
	string row10 = "|            |       ~~~~~~~~~~~~      |                |\n";
	string row09 = "|  BILLIARD  |                         |---|            |\n";
	string row08 = "|    ROOM    |                             |------------|\n";
	string row07 = "|------------|                                          |\n";
	string row06 = "|                  |------------------|                 |\n";
	string row05 = "|                  |                  |   |-------------|\n";
	string row04 = "|-----------|_     |                  |   |             |\n";
	string row03 = "|            |     |     BALLROOM     |   |             |\n";
	string row02 = "|CONSERVATORY|     |                  |   |   KITCHEN   |\n";
	string row01 = "|            |     |--|            |--|   |             |\n";
	string row00 = "|-------------------------------------------------------|\n";

	// Fill the board with strings
	for (int j = 0; j < 57; j++) {
		board[0][j] = row24[j];
		board[1][j] = row23[j];
		board[2][j] = row22[j];
		board[3][j] = row21[j];
		board[4][j] = row20[j];
		board[5][j] = row19[j];
		board[6][j] = row18[j];
		board[7][j] = row17[j];
		board[8][j] = row16[j];
		board[9][j] = row15[j];
		board[10][j] = row14[j];
		board[11][j] = row13[j];
		board[12][j] = row12[j];
		board[13][j] = row11[j];
		board[14][j] = row10[j];
		board[15][j] = row09[j];
		board[16][j] = row08[j];
		board[17][j] = row07[j];
		board[18][j] = row06[j];
		board[19][j] = row05[j];
		board[20][j] = row04[j];
		board[21][j] = row03[j];
		board[22][j] = row02[j];
		board[23][j] = row01[j];
		board[24][j] = row00[j];
	}

}

/* clearPlayer() is a void method without parameters. It removes the player's
 * previous location from the board. It is called when the player is moved to
 * a new room. */
void Map::clearPlayer() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 57; j++) {
			if (board[i][j] == '*') {
				board[i][j] = ' ';
			}
		}
	}
}

/* The following nine methods do not have parameters and return void. They
 * place the Player in the appropriate room. */
void Map::placeStudy() {
	clearPlayer();
	board[3][12] = '*';
}

void Map::placeLibrary() {
	clearPlayer();
	board[9][10] = '*';
}

void Map::placeBilliards() {
	clearPlayer();
	board[14][4] = '*';
}

void Map::placeConservatory() {
	clearPlayer();
	board[21][4] = '*';
}

void Map::placeBallroom() {
	clearPlayer();
	board[19][29] = '*';
}

void Map::placeHall() {
	clearPlayer();
	board[2][27] = '*';
}

void Map::placeLounge() {
	clearPlayer();
	board[2][50] = '*';
}

void Map::placeDining() {
	clearPlayer();
	board[10][51] = '*';
}

void Map::placeKitchen() {
	clearPlayer();
	board[21][47] = '*';
}

/* printBoard is a void method without parameters. It prints out the board. */
void Map::printBoard() const {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 57; j++) {
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

/* printKey is a void method without parameters. It displays the key for
 * the board. */
void Map::printKey() const {
	std::cout << "\t\t\t\t\t\tKEY: * YOU ARE HERE" << std::endl;
}