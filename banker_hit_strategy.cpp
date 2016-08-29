/*
 * banker_hit_strategy.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: jeff
 */

#include "banker_hit_strategy.h"

bool BankerHitStrategy::shouldHit(Hand& player, Hand& banker)
{
    auto playerTotal = player.getTotal();
    auto bankerTotal = banker.getTotal();
    auto cardsDrawn = player.getCardsDrawn();
    auto lastCardValue = player.getLastCardValue();

    if (playerTotal >= 8 || bankerTotal >= 8) {
        return false;
    } else if (cardsDrawn > 2) {
        return ifPlayerStood(bankerTotal);
    } else {
        return ifPlayerHit(bankerTotal, lastCardValue);
    }
}

bool BankerHitStrategy::ifPlayerStood(const int bankerTotal)
{
    if (bankerTotal >= 6) {
        return false;
    } else {
        return true;
    }
}

bool BankerHitStrategy::ifPlayerHit(const int bankerTotal, const int lastCardValue)
{
    switch (bankerTotal) {
    case 7:
        return false;

    case 6:
        if (lastCardValue == 6 || lastCardValue == 7) {
            return true;
        } else {
            return false;
        }

    case 5:
        if (lastCardValue >= 4 && lastCardValue <= 7) {
            return true;
        } else {
            return false;
        }

    case 4:
        if (lastCardValue >= 2 && lastCardValue <= 7) {
            return true;
        } else {
            return false;
        }

    case 3:
        if (lastCardValue != 8) {
            return true;
        } else {
            return false;
        }

    default:
        return false;
    }
}


