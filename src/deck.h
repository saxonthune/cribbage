#pragma once
#include "./card.h"

class deck {
	private:
		card cards[52];
		int num_cards;
		void remove_card();
	public:
		deck();
		void shuffle();
		void reset();
		//void remove_card();
		card deal_top_card();
		bool out_of_cards();
		void add_card(card);

		//debug functions
		void print_all_cards();
};

