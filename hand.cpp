/*
 * hand.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: jeff
 */

#include "hand.h"
#include "hit_strategy.h"

Hand::Hand(HitStrategy* hitStrategy) : _hitStrategy(hitStrategy), _total(0), _isCutCard(false) {}

void Hand::accumulate(int value)
{
    _total += value;
    _total %= 10;
}

int Hand::getTotal() const
{
	return _total;
}

void Hand::draw(Shoe& shoe)
{
    PlayingCard* card;
    card = &shoe.deal();
    if (card->getId() == Shoe::Cut_Card.getId()) {
        card = &shoe.deal();
        _isCutCard = true;
    }
    accumulate(card->getValue());
}

bool Hand::wasCutCardDrawn()
{
    return _isCutCard;
}

bool Hand::shouldHit(const int playerTotal, const int bankerTotal, PlayingCard* playerHitCard)
{
    return _hitStrategy->shouldHit(playerTotal, bankerTotal, playerHitCard);
}
