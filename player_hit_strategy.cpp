/*
 * player_hit_strategy.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: jeff
 */

#include "player_hit_strategy.h"

bool PlayerHitStrategy::shouldHit(Hand& player, Hand& banker)
{
    auto playerTotal = player.getTotal();
    auto bankerTotal = banker.getTotal();

    if (playerTotal >= 8 || bankerTotal >= 8) {
        return false;
    } else if (playerTotal >= 6) {
        return false;
    } else {
        return true;
    }
}



