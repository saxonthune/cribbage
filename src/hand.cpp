#include "./hand.h"
#include <iostream>
#include <vector>

/******************************************************************
//Function:  hand::hand()
//Description: Default constructor
//Input: None
//Output: Member of hand class
******************************************************************/
hand::hand() {
	cards = new card[0];
	num_cards = 0;
}

/******************************************************************
//Function: hand::hand(deck &)
//Description: Creates hand by taking the top two cards from a
//	given deck.
//Input: Deck (by reference)
//Output: Member of hand class
******************************************************************/
hand::hand(deck &myDeck, int size) {

	num_cards = size;
	cards = new card[size];

	for (int i = 0; i < size; i++) {
		cards[i] = myDeck.deal_top_card();
	}
}

/******************************************************************
//Function: hand::~hand()
//Description: Default destructor
//Input: None
//Output: None
******************************************************************/
hand::~hand() {

	delete[] cards;
}

/******************************************************************
//Function: hand:hand(const hand&)
//Description: copy constructor for hand;
//Input: Hand (by reference) to be copied
//Output: Member of hand class
******************************************************************/
hand::hand(const hand & that) {

	num_cards = that.get_num_cards();
	cards = new card[ num_cards ];
	for (int i = 0; i < num_cards; i++) {
		cards[i] = that.get_card(i);
	}
}

/******************************************************************
//Function: hand::operator=(const hand&)
//Description: Operator overload for hand class.
//Input: hand (by reference) to copy
//Output: Member of hand class
******************************************************************/
void hand::operator=(const hand & that) {

	num_cards = that.get_num_cards();
	cards = new card[ num_cards ];
	for (int i = 0; i < num_cards; i++) {
		cards[i] = that.get_card(i);
	}
}

/******************************************************************
//Function: hand::get_num_cards() const
//Description: Accessor; returns the number of cards in hand.
//Input: None
//Output: Int (number of cards)
******************************************************************/
int hand::get_num_cards() const {

	return num_cards;
}

/******************************************************************
//Function: hand::get_card(int) const
//Description: Returns card at given position in card array
//Input: int (used for index)
//Output: Member of card class
******************************************************************/
card hand::get_card(int index) const {

	return cards[index];
}

/******************************************************************
//Function: hand::add_card(card)
//Desc: Adds specified card to hand
******************************************************************/
void hand::add_card(card inCard) {

	card * newCards = new card[ num_cards +1];

	for (int i = 0; i < num_cards; i++) {

		newCards[i] = cards[i];
	}
	delete[] cards;
	newCards[num_cards] = inCard;
	num_cards++;

	cards = newCards;
	newCards = NULL;

}

/******************************************************************
//Function: hand::sort_by_value(int)
//Desc: Sort cards by value; aces are considered as the lowest
//Param: bool determines descending (false) or ascending (true)
//Pre-cond: hand is initialized
//Post-cond: hand is sorted
******************************************************************/
/*
void hand::sort_by_value(bool ascend) {

	//make temporary hand
	hand tmphand = hand(this);
	split_hand();////aaaaaaaaaaaaaaa

	*/


/******************************************************************
//Function: hand::find_val_count()
//Desc: Finds how many cards have each number value
//Param: None
//Pre-cond: hand is initialized and nonempty
//Post-cond: Returns a pointer to an int array which describes the
//	frequency of each value in the hand. E.g., if the hand values are
//	{A, 3, 3, J, Q}, then the array is {1,0,2,0,0,0,0,0,0,0,0,1,1,0}
******************************************************************/
std::vector<int> hand::count_by_value() {

	//int* valcount = new int[13];
	std::vector<int> valcount(13);

	for (int i = 0; i < get_num_cards(); i++) {

		//find index corresponding to value of i'th card, and increment
		//value at that index
		valcount[get_card(i).get_value(true)-1]++;
	}

	return valcount;
}
/******************************************************************
//Function: hand::count_runs()
//Desc: Finds the number of runs in a hand, including double-,triple-,
//	etc. runs.
//Param: None
//Pre-cond: hand is initialized and nonempty
//Post-cond: Returns a pointer to an int array describing the frequency
//	of each run, where the index corresponds to the size (starting with a
//	run of 2). E.g., if the hand is {A,2,2,3,6,7,8,9}, then the array is
//	{0,2,1,0,0,0,0,0,0,0,0,0}
//NOTE: Currently, Aces are considered low
******************************************************************/
std::vector<int> hand::count_runs() {

	std::vector<int> valcount = count_by_value();
	std::vector<int> runcount(13);

	//std::cout << "memes" << std::endl;
	int count, j;
	//loop checks for continuous runs above index, so stop at 12 (queen)
	for (int i = 0; i < 12; i++) {

		//std::cout << "loop #" <<  i+1; 
		//std::cout << ", count is " << valcount[i] << std::endl;

		if (valcount[i] > 0) {
			//std::cout << "\t wew";
			count = valcount[i];
			//std::cout << " lad";
			for (j = i+1; valcount[j] < 13; j++) {
				if (valcount[j] == 0)
					break;
				//std::cout << " j is " << j;
				count *= valcount[j]; //see "rule of product" in combinatorics
			}

			//std::cout << std::endl;
			
			runcount[j-i-1] += count;
			i = j;					//this prevents over-counting (ie, subruns)
		}
	}

	return runcount;
}
/******************************************************************
//Function: hand::count_totals(int, bool)
//Desc: For some int n, finds the number of combinations that sum to n
//Param: int n -- function finds n.o. combinations that sum to
//      bool faceValue -- if false, then face cards have value 10
//Pre-cond: hand is initialized and nonempty
//Post-cond: returns number of combinations, hand is unchanged
//NOTE: for hand size N, there are (2^N)-1 possible combinations to check
******************************************************************/
int hand::count_totals(int n, bool faceValue) {

    return 0;
}
/******************************************************************
//Function: hand::count_like_values(int)
//Desc: Finds number of pairs, triplets, etc. in hand
//Param: int n -- function looks for n-of-a-kind in hand
//Pre-cond: hand is initialized and nonempty
//Post-cond: returns number of n-of-a-kind observed
******************************************************************/
int hand::find_like_values(int n) {

    std::vector<int> valCount = count_by_value();
    int sum = 0;

    for (int i=0; i < 13; i++) {
        if (valCount[i] == n) {
            sum++;
        }
    }
    return sum;
}
/******************************************************************
//Function: hand::check_flush()
//Desc: Determines whether all cards are of same suit
//Param: None
//Pre-cond: Hand is initialized and has more than 1 one card
//Post-cond: 
******************************************************************/
bool hand::check_flush() {

    char suit = get_card(0).get_suit();

    //check if each card has same suit as the first card
    for (int i = 1; i < get_num_cards(); i++) {

        if (suit != get_card(i).get_suit()) {
            return false;       //found a card that is diff suit, so return 0
        }
    }
    return true;
}
/******************************************************************
//Function: hand::add_card_to_hand(deck &)
//Description: Accessor; takes the "top" card from a deck and places
//	it in the hand's array of cards.
//Input: deck (by reference) to draw cards from
//Output: None
******************************************************************/
void hand::add_from_deck(deck &myDeck) {

	card * newCards = new card[ num_cards + 1 ];

	for (int i = 0; i < num_cards; i++) {

		newCards[i] = cards[i];
	}
	delete[] cards;
	newCards[num_cards] = myDeck.deal_top_card();
	num_cards++;

	cards = newCards;
	//delete[] newCards;
	newCards = NULL;

}

/******************************************************************
//Function: hand::print()
//Description: Prints the value of each card; calls each card's
//	print function individually.
//Input: None
//Output: None; prints to console.
******************************************************************/
void hand::print() {

	for (int i = 0; i < num_cards; i++) {

		cards[i].print_card();
	}
	std::cout << std::endl;
}

/******************************************************************
//Function:
//Desc:
//Param:
//Pre-cond:
//Post-cond:
******************************************************************/

