/*
 * hand.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: jeff
 */

#include "hand.h"

Hand::Hand() : _total(0)
{
}

int Hand::total() const
{
	return _total;
}

int Hand::numberOfCards() const
{
	return 0;
}

void Hand::discard()
{
	_hand.clear();
	_total = 0;
}
