/*
 * player_hit_strategy.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: jeff
 */

#include "player_hit_strategy.h"

bool PlayerHitStrategy::shouldHit(const int playerTotal, const int bankerTotal, PlayingCard* playerHitCard)
{
    if (playerTotal >= 8 || bankerTotal >= 8) {
        return false;
    } else if (playerTotal >= 6) {
        return false;
    } else {
        return true;
    }
}



