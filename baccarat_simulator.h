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

private:
	int _cycles;
	int _shuffles;
	int _cyclesComplete;
	int _handsLeft;
	const int numberOfDecks = 8;
	const int cutCardPosition = 16;
	Shoe _shoe;

	void playCycle();
	void playHand();
};



#endif /* BACCARAT_SIMULATOR_H_ */
