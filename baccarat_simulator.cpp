/*
 * baccarat_simulator.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: jeff
 */

#include "baccarat_simulator.h"
#include "banker_hit_strategy.h"
#include "player_hit_strategy.h"
#include "hand.h"
#include <limits>

using namespace std;

BaccaratSimulator::BaccaratSimulator(int cycles, int shuffles) :
	_cycles(cycles),
	_shuffles(shuffles),
	_cyclesComplete(0),
	_shoe(numberOfDecks),
	_totalHands(0),
	_playerWins(0),
	_bankerWins(0),
	_ties(0),
	_handsLeft(0) {}

BaccaratSimulator::~BaccaratSimulator() {}

void BaccaratSimulator::run()
{
	while (_cyclesComplete < _cycles) {
		playCycle();
		_cyclesComplete++;
	}
}

void BaccaratSimulator::playCycle()
{
    // Reset shoe
    _shoe.shuffle(_shuffles);
    _shoe.insertCutCard(cutCardPosition);
    PlayingCard card = _shoe.deal();
    _shoe.discard(card.getValue());
    // At this point, we don't know how many hands are left in the cycle,
    // so we'll set _handsLeft to an impossibly large value.
    _handsLeft = std::numeric_limits<int>::max();

    // Play the hands
    while (_handsLeft > 0) {
        playHand();
        _handsLeft--;
    }
}

void BaccaratSimulator::playHand()
{
    Hand player(new PlayerHitStrategy());
    Hand banker(new BankerHitStrategy());

    player.draw(&_shoe);
    if (player.wasCutCardDrawn()) {
        _handsLeft = 1;
    }
    banker.draw(&_shoe);
    if (banker.wasCutCardDrawn()) {
        _handsLeft = 2;
    }
    player.draw(&_shoe);
    if (player.wasCutCardDrawn()) {
        _handsLeft = 2;
    }
    banker.draw(&_shoe);
    if (banker.wasCutCardDrawn()) {
        _handsLeft = 2;
    }

    if (player.shouldHit(player, banker)) {
        player.draw(&_shoe);
        if (player.wasCutCardDrawn()) {
            _handsLeft = 2;
        }
    }

    if (banker.shouldHit(player, banker)) {
        banker.draw(&_shoe);
        if (banker.wasCutCardDrawn()) {
            _handsLeft = 2;
        }
    }

    _totalHands++;
    if (player.getTotal() > banker.getTotal()) {
        _playerWins++;
    } else if (player.getTotal() < banker.getTotal()) {
        _bankerWins++;
    } else {
        _ties++;
    }

}
