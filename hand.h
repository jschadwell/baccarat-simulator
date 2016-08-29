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
#include <memory>

class HitStrategy;
class Hand {
public:
	Hand(HitStrategy* hitStrategy);

	int getTotal() const;
	void draw(Shoe* shoe);
	int getCardsDrawn() const;
	int getLastCardValue() const;
	bool wasCutCardDrawn();
	bool shouldHit(Hand& player, Hand& banker);

private:
	std::unique_ptr<HitStrategy> _hitStrategy;
	int _total;
	int _cardsDrawn;
	int _lastCardValue;
	bool _isCutCard;

	void accumulate(int value);
};

#endif /* HAND_H_ */
