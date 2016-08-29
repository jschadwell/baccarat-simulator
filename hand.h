/*
 * hand.h
 *
 *  Created on: Aug 29, 2016
 *      Author: jeff
 */

#ifndef HAND_H_
#define HAND_H_

#include "playing_card.h"
#include "shoe.h"
#include <vector>

class Hand {
public:
	Hand(/* Hit strategy set here */);

	int total() const;
	int numberOfCards() const;
	void discard();

private:
	std::vector<PlayingCard> _hand;
	int _total;
};

#endif /* ABSTRACT_HAND_H_ */
