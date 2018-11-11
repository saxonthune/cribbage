DRIVER = scoretest

driver: $(DRIVER).o cribbage.o deck.o card.o hand.o 
	g++ -g -std=c++11 $(DRIVER).o cribbage.o deck.o card.o hand.o -o $(DRIVER)
$(DRIVER).o: $(DRIVER).cpp
	g++ $(DRIVER).cpp -std=c++11 -c
cribbage.o: ../src/cribbage.cpp
	g++ ../src/cribbage.cpp -std=c++11 -c
deck.o: ../src/deck.cpp
	g++ ../src/deck.cpp -std=c++11 -c
card.o: ../src/card.cpp
	g++ ../src/card.cpp -std=c++11 -c
hand.o: ../src/hand.cpp
	g++ ../src/hand.cpp -std=c++11 -c


clean:
	rm -rf $(DRIVER) *.o
