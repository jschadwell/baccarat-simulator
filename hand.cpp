/*
 * hand.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: jeff
 */

#include "hand.h"
#include "hit_strategy.h"

#include <iostream>

Hand::Hand(HitStrategy* hitStrategy) :
    _hitStrategy(hitStrategy),
    _total(0),
    _isCutCard(false),
    _cardsDrawn(0),
    _lastCardValue(0) {}

void Hand::accumulate(int value)
{
    _total += value;
    _total %= 10;
}

int Hand::getTotal() const
{
	return _total;
}

void Hand::draw(Shoe* shoe)
{
    PlayingCard card = shoe->deal();
    if (card.getId() == Shoe::Cut_Card.getId()) {
        card = shoe->deal();
        _isCutCard = true;
    }
    _lastCardValue = card.getValue();
    accumulate(_lastCardValue);
    _cardsDrawn++;
}

int Hand::getCardsDrawn() const
{
    return _cardsDrawn;
}

int Hand::getLastCardValue() const
{
    return _lastCardValue % 10;
}

bool Hand::wasCutCardDrawn()
{
    return _isCutCard;
}

bool Hand::shouldHit(Hand& player, Hand& banker)
{
    return _hitStrategy->shouldHit(player, banker);
}
