#include "./card.h"
#include <iostream>
#include <string>

using namespace std;


/******************************************************************
//Function: card::card()
//Description: Default constructor
//Input: None
//Output: Member of class card
******************************************************************/
card::card() {
	value = 0;
	suit = 'N';
}

/******************************************************************
//Function: card::card(int, char)
//Description: Constructor; create card within given value and suit
//Input: Int correspoinding to value, char correspoding to suit
//Output: Member of class card
******************************************************************/
card::card(int inValue, char inSuit) {
	value = inValue;
	suit = inSuit;
}

/******************************************************************
//Function: card::get_value()
//Description: Accessor function; returns (numerical) value of card
//Param: bool - determines whether face cards are worth 10 or 11,12,13
//      respectively
//Pre-cond:
//Post-cond:
******************************************************************/
int card::get_value(bool faceValue) {

    if ((!faceValue) && value > 9) {
        return 10;
    }
	return value;
}

/******************************************************************
//Function: card::get_suit()
//Description: Accessor function; returns char correspoinding to suit
//Input: None
//Output: Char
******************************************************************/
char card::get_suit() {
	return suit;
}

/******************************************************************
//Function:
//Description: Prints value and suit (first letter) of card
//Input: None
//Output: None; text to console
******************************************************************/
void card::print_card() {

	string value;
	bool isLetter = false;

	if (get_value(true) == 11) {

		value = "J-";
		isLetter = true;
	}
	else if (get_value(true) == 12) {

		value = "Q-";
		isLetter = true;
	}
	else if (get_value(true) == 13) {

		value = "K-";
		isLetter = true;
	}
	else if (get_value(true) == 1) {
		value = "A-";
		isLetter = true;
	}

	if (isLetter) {
		std::cout << value << get_suit() << ", ";
	}
	else {
		std::cout << get_value(true) << "-" << get_suit() << ", ";
	}
}
