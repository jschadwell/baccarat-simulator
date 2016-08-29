/*
 * banker_hit_strategy.h
 *
 *  Created on: Aug 29, 2016
 *      Author: jeff
 */

#ifndef BANKER_HIT_STRATEGY_H_
#define BANKER_HIT_STRATEGY_H_

#include "hit_strategy.h"

class BankerHitStrategy : public HitStrategy {
public:
    bool shouldHit(const int playerTotal, const int bankerTotal, PlayingCard* playerHitCard = nullptr) override;

private:
    bool ifPlayerStood(const int bankerTotal);
    bool ifPlayerHit(const int bankerTotal, PlayingCard* playerHitCard);
};

#endif /* BANKER_HIT_STRATEGY_H_ */
