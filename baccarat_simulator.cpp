/*
 * baccarat_simulator.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: jeff
 */

#include "baccarat_simulator.h"
#include <iostream>

using namespace std;

BaccaratSimulator::BaccaratSimulator(int cycles, int shuffles) :
	_cycles(cycles),
	_shuffles(shuffles),
	_cyclesComplete(0),
	_shoe(numberOfDecks) {}

BaccaratSimulator::~BaccaratSimulator() {}

void BaccaratSimulator::run()
{
	while (_cyclesComplete < _cycles) {
		playCycle();
		_cyclesComplete++;
		std::cout << "Cycles complete = " << _cyclesComplete << std::endl;
	}
}

void BaccaratSimulator::playCycle()
{
    // Reset shoe
    _shoe.shuffle(_shuffles);
    PlayingCard card = _shoe.deal();
    _shoe.discard(card.getValue());
    _shoe.insertCutCard(cutCardPosition);
}
