#pragma once
#include "./deck.h"
#include "./hand.h"

class cribbage {

    private:
        deck cribDeck;
        hand *h1;
        hand *h2;
        hand *crib;
		card starter;

    public:
        cribbage();

        void play_round();
        std::vector<int> report_scores();

        hand* select_best_hand(hand*);
        int score_hand(hand, card);



};


