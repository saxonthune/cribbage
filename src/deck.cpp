#include "./deck.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

/******************************************************************
//Function: deck::deck()
//Description: Contructor; creates deck of 52 cards, unshuffled
//	(values 1-13, suits Hearts, Diamonds, Clubs, Spades).
//Input: None
//Output: Member of deck class
******************************************************************/
deck::deck() {

	num_cards = 52;
	char inSuit;
	inSuit = 'H';
	srand(time(0));

	for (int i=0; i<4; i++) {

		if (i == 1)
			inSuit = 'D';
		if (i == 2)
			inSuit = 'C';
		if (i == 3)
			inSuit = 'S';

		for (int j=0; j<13; j++) {

			cards [(i*13)+j] = card(j+1, inSuit);
		}
	}
}

/******************************************************************
//Function: deck::shuffle()
//Description: Shuffles cards in deck via rand().
//Input: None
//Output: None
******************************************************************/
void deck::shuffle() {

	int random;
	card tempCard;

	for (int i =0; i < num_cards; i++) {

		random = rand() % (52);
		tempCard = cards[i];
		cards[i] = cards[random];
		cards[random] = tempCard;
		}
}

/******************************************************************
//Function: deck::remove_card()
//Description: Mutator; "removes" card from deck by decreasing
//	number of undealt cards.
//Input: None
//Output: None
******************************************************************/
void deck::remove_card() {
	num_cards --;
}

/******************************************************************
//Function: deck::reset()
//Description: resets deck to full and shuffles
//Input: None
//Output:
******************************************************************/
void deck::reset() {

    num_cards = 52;
    shuffle();
}
/******************************************************************
//Function: deck::deal_top_card()
//Description: returns card "on top" of deck and removes it from deck
//Input: None
//Output: Member of card class
******************************************************************/
card deck::deal_top_card() {

	if (out_of_cards()) {
		cout << "*************** Out of cards! using new deck..."
			" ***************" << endl;
		num_cards = 52;
	}
	remove_card();
	return cards[num_cards];
}

/******************************************************************
//Function: deck::out_of_cards
//Description: Checks deck to see if every card has been dealt.
//Input: None
//Output: bool
******************************************************************/
bool deck::out_of_cards() {

	if (num_cards < 1)
		return true;
	return false;
}

/******************************************************************
//Function: deck::print_all_cards()
//Description: Prints value of every card in order.
//Input: None
//Output: None; prints to console
******************************************************************/
void deck::print_all_cards(){

	for (int i=0; i < 52; i++) {
		cards[i].print_card();
	}
}








