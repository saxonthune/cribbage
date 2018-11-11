#include <iostream>
#include "../src/cribbage.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void store_results(string filename, int numTrials, cribbage crib) {

    std::vector<int> score(3);
    ofstream file;
    file.open(filename);

    for (int i = 0; i < numTrials; i++) {

        score = crib.report_scores();
        file << score[0];
		if (i < numTrials-1)
			file << ",";
    }
	file << "\n";
    file.close();
}

int main() {

    cribbage crib = cribbage();
	store_results("hand_values.csv", 50000, crib);

	return 0;
}

