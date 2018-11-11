#pragma once
#include "./deck.h"
#include <vector>

class hand {
	private:
		int num_cards;

	public:

		card * cards;
		hand();
		hand(deck &, int);
		~hand();
		hand(const hand &);
		void operator=(const hand &);
		void set_num_cards(int);
		card * get_cards();
		int get_num_cards() const;
		card get_card(int) const;
		void add_card(card);

	//	void sort_by_value(bool)
		std::vector<int> count_by_value();
		std::vector<int> count_runs();
		int count_totals(int, bool);
		int find_like_values(int);
		bool check_flush();

		void add_from_deck(deck &);
		void print();
};
