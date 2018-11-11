#include <iostream>
#include "./cribbage.h"
#include <vector>
#include <fstream>

using namespace std;

int main() {

/*	deck myDeck = deck();
	myDeck.shuffle();
	int score;

	hand myHand = hand(myDeck, 6);
	hand otherHand = select_best_hand(myHand);

	//print starting hand
	cout << "STARTING HAND: ";
	myHand.print();

	//print best choice
	cout << "BEST CHOICE: ";
	otherHand.print();

	//print hand with random 5th card
	cout << "\n\nFinal Hand with 5th card: ";
	otherHand.add_card( myDeck.deal_top_card() );
	otherHand.print();

	//compute and print score
	score = score_hand(otherHand);
	cout << "SCORE: " << score << endl;

    deck myDeck = deck();
    myDeck.shuffle();
    hand myHand = hand(myDeck, 8);
    myHand.print();

    cout << endl;
    std::vector<int> vals = myHand.count_runs();
    for (int i =0; i < 13; i++) {
        cout << vals[i] << "  ";
    }
    myHand = hand();
    myHand.add_card(card(3,'H'));
    myHand.add_card(card(4,'H'));
    myHand.add_card(card(5,'H'));
    myHand.add_card(card(6,'H'));
    myHand.add_card(card(7,'H'));
    myHand.add_card(card(8,'H'));
    //myHand.print();
*/

    cribbage game = cribbage();

    std::vector<int> score(3);
    ofstream myFile;
    myFile.open ("scoresbig.txt");

    for (int i = 0; i < 1000000; i++) {

        score = game.report_round();
        //std::cout << score[0] << ",";
        myFile << score[0] << "\n";

    }
    myFile.close();

	return 0;
}
