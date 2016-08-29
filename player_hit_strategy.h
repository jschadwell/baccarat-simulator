/*
 * player_hit_strategy.h
 *
 *  Created on: Aug 29, 2016
 *      Author: jeff
 */

#ifndef PLAYER_HIT_STRATEGY_H_
#define PLAYER_HIT_STRATEGY_H_

#include "hit_strategy.h"

class PlayerHitStrategy : public HitStrategy {
public:
    bool shouldHit(Hand& player, Hand& banker) override;
};

#endif /* PLAYER_HIT_STRATEGY_H_ */
