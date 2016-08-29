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

class Shoe {
public:
    static PlayingCard Cut_Card;

    Shoe(const int numberOfDecks);

    void shuffle(const int numberOfShuffles);
    PlayingCard& deal();
    void discard(int numberToDiscard = 1);
    void insertCutCard(const int cutCardPosition);

private:
    std::vector<PlayingCard> _shoe;
    std::vector<PlayingCard>::iterator _pos;
};

#endif /* SHOE_H_ */
