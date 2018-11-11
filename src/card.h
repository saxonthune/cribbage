#pragma once

class card {
	private:
		int value;
		char suit;
	public:
		card();
		card(int, char);
		int get_value(bool);
		char get_suit();
		void print_card();
};

