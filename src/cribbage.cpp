#include <iostream>
#include "./cribbage.h"
#include <vector>

//The cribbage object is an instance of a two-player gmae
// of cribbage.

/******************************************************************
//Default Constructor
******************************************************************/
cribbage::cribbage() {

    cribDeck = deck();
    cribDeck.shuffle();
    //h1 = hand();
    //h2 = hand();
    //crib = hand();
}
/******************************************************************
//Returns vector with the scores of three hands: one from each of 
// the players, and the crib hand
******************************************************************/
std::vector<int> cribbage::report_scores() {

    std::vector<int> scores(3);

    h1 = new hand(cribDeck, 6);
    hand* h1_best = select_best_hand(h1);
	h2 = new hand(cribDeck, 6);
	hand* h2_best = select_best_hand(h2); 

	//todo: make crib hand using discards from h1,h2
	//crib = hand(...

	//add the shared "starter" card to each hand
    starter = cribDeck.deal_top_card();

    scores[0] = score_hand(*h1_best, starter);
    scores[1] = score_hand(*h2_best, starter);
    //scores[2] ...

    //reset everything
    cribDeck.reset();
	delete h1;
	delete h2;
	delete h1_best;
	delete h2_best;
    //delete crib

    return scores;

}
/******************************************************************
//Chooses every 4-card subset of myHand paramater and 
// returns highest scoring option
******************************************************************/
hand* cribbage::select_best_hand(hand *myHand) {

	int size = myHand->get_num_cards();
	hand *smallHand;
	hand *bestHand = new hand();
	int score, topScore;

	topScore = 0;

	//these loops iterate through the hand to pick every combination of size 4
	for (int i = 0; i < size-3; i++) {
	for (int j = i+1; j < size-2; j++) {
	for (int k = j+1; k < size-1; k++) {
	for (int m = k+1; m < size; m++) {

		//set smaller hands with current config of i,j,k,m
		smallHand = new hand();
		smallHand->add_card(myHand->get_card(i));
		smallHand->add_card(myHand->get_card(j));
		smallHand->add_card(myHand->get_card(k));
		smallHand->add_card(myHand->get_card(m));

		score = score_hand(*smallHand, card());

		if (score > topScore) {

			topScore = score;
			delete bestHand;
			bestHand = new hand(*smallHand);
		}
		delete smallHand;

	}
	}
	}
	}
	return bestHand;

}
/******************************************************************
//Sums points earned with given hand and returns total
******************************************************************/
int cribbage::score_hand(hand myHand, card starter) {

    int sum = 0;

	//create hand
	hand bigHand = hand();
	for (int i = 0; i < myHand.get_num_cards(); i++)
		bigHand.add_card(myHand.get_card(i));
	//add starter card if applicable
	if (starter.get_value(false) != 0)
		bigHand.add_card(starter);

    //check for 2,3,4 of-a-kind
    sum += 2*(bigHand.find_like_values(2));
    sum += 6*(bigHand.find_like_values(3));
    sum += 12*(bigHand.find_like_values(4));

    //check for runs
    std::vector<int> runs = bigHand.count_runs();
    for (int i = 2; i < 13; i++) {
        sum += runs[i] * (i+1);
    }

    //count for flush
	if (bigHand.check_flush())
    	sum += 5;
	else if (myHand.check_flush())
		sum += 4;

    /*======= Counting 15's =========*/
    //todo: remove repeated code with a check_value_sum function
	int cTotal = bigHand.get_num_cards();

	//check all pairwise combinations
	for (int i = 0; i < cTotal - 1; i++) {
		for (int j = i+1; j < cTotal; j++) {

			//check for 15
			if (bigHand.get_card(i).get_value(false)
					+bigHand.get_card(j).get_value(false) == 15) {
				sum +=2;
			}
		}
	}
	//check all 3-wise combinations
	for (int i = 0; i < cTotal - 2; i++) {
		for (int j = i+1; j < cTotal - 1; j++) {
			for (int k = j+1; k < cTotal; k++) {

				//check for 15
				if (bigHand.get_card(i).get_value(false)
						+bigHand.get_card(j).get_value(false)
						+bigHand.get_card(k).get_value(false) == 15)
			   	{
					sum +=2;
				}
			}
		}
	} //end 3-wise combinations

	//check all 4-wise combinations
	//todo: instead of 4 loops, use 1 loop to exclude a
	// (since n-choose-k gives as many combinations as n-choose-(n-k))
	for (int i = 0; i < cTotal -3; i++) {
	for (int j = i+1; j < cTotal -2; j++) {
	for (int k = j+1; k < cTotal -1; k++) {
	for (int m = k+1; m < cTotal; m++) {

		//check for 15
		if (bigHand.get_card(i).get_value(false)
                +bigHand.get_card(j).get_value(false)
				+bigHand.get_card(k).get_value(false)
				+bigHand.get_card(m).get_value(false) == 15) {
			sum+=2;
		}
	}
	}
	}
	} //end 4-wise combination

if (cTotal == 5) {
	//check all 5-wise combinations
	//check for 15
	if (bigHand.get_card(0).get_value(false)
            +bigHand.get_card(1).get_value(false)
			+bigHand.get_card(2).get_value(false)
			+bigHand.get_card(3).get_value(false)
			+bigHand.get_card(4).get_value(false) == 15) {
		sum +=2;
	}

	//check for knobs, if counting with starter
	//check for jack in first 4 cards
	for (int i = 0; i < 4; i++) {
		//check for jack
		if (bigHand.get_card(i).get_value(true) == 11) {
			//check for matching suit
			if (bigHand.get_card(i).get_suit() == bigHand.get_card(4).get_suit()){
				sum +=1;
			}
		}
	}
	} //ends (cTotal == 5) loop

	if (sum == 19) {
		std::cout << "19 FOUND: ";
		bigHand.print();
	}

	return sum;
}





