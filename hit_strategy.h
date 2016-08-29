/*
 * hit_strategy.h
 *
 *  Created on: Aug 29, 2016
 *      Author: jeff
 */

#ifndef HIT_STRATEGY_H_
#define HIT_STRATEGY_H_

#include "hand.h"
#include "playing_card.h"

class HitStrategy {
public:
    virtual ~HitStrategy() {}

    virtual bool shouldHit(Hand& player, Hand& banker) = 0;
};



#endif /* HIT_STRATEGY_H_ */
