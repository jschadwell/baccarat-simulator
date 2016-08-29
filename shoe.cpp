/*
 * shoe.cpp
 *
 *  Created on: Aug 28, 2016
 *      Author: jeff
 */

#include "shoe.h"
#include <algorithm>

Shoe::Shoe(const int numberOfDecks)
{
	int i;
	for (i = 0; i < numberOfDecks; i++) {
		// Create decks here
	}
}

void Shoe::shuffle(const int numberOfShuffles)
{
	int i;
	for (i = 0; i < numberOfShuffles; i++) {
		random_shuffle(begin(_shoe), end(_shoe));
	}
	_pos = begin(_shoe);
}

PlayingCard& Shoe::deal()
{
	return *(_pos++);
}

void Shoe::discard()
{
	++_pos;
}


