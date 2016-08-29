/*
 * shoe.h
 *
 *  Created on: Aug 28, 2016
 *      Author: jeff
 */

#ifndef SHOE_H_
#define SHOE_H_

#include "playing_card.h"
#include <vector>

using namespace std;

class Shoe {
public:
	Shoe(const int numberOfDecks);

	void shuffle(const int numberOfShuffles);
	PlayingCard& deal();
	void discard();

private:
	vector<PlayingCard> _shoe;
	vector<PlayingCard>::iterator _pos;
};



#endif /* SHOE_H_ */
