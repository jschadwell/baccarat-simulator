/*
 * baccarat_simulator.h
 *
 *  Created on: Aug 29, 2016
 *      Author: jeff
 */

#ifndef BACCARAT_SIMULATOR_H_
#define BACCARAT_SIMULATOR_H_

#include "shoe.h"

class BaccaratSimulator {
public:
    BaccaratSimulator(int cycles, int shuffles);
    ~BaccaratSimulator();

    void run();
    int getTotalHands() const { return _totalHands; }
    int getPlayerWins() const { return _playerWins; }
    int getBankerWins() const { return _bankerWins; }
    int getTies() const { return _ties; }

private:
    int _cycles;
    int _shuffles;
    int _cyclesComplete;
    int _handsLeft;
    int _totalHands;
    int _playerWins;
    int _bankerWins;
    int _ties;
    const int numberOfDecks = 1;
    const int cutCardPosition = 16;
    Shoe _shoe;

    void playCycle();
    void playHand();
};



#endif /* BACCARAT_SIMULATOR_H_ */
