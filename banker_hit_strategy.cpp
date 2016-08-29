/*
 * banker_hit_strategy.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: jeff
 */

#include "banker_hit_strategy.h"

bool BankerHitStrategy::shouldHit(const int playerTotal, const int bankerTotal, PlayingCard* playerHitCard)
{
    if (playerTotal >= 8 || bankerTotal >= 8) {
        return false;
    } else if (playerHitCard == nullptr) {
        return ifPlayerStood(bankerTotal);
    } else {
        return ifPlayerHit(bankerTotal, playerHitCard);
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

bool BankerHitStrategy::ifPlayerHit(const int bankerTotal, PlayingCard* playerHitCard)
{
    auto hitCardValue = playerHitCard->getValue();
    switch (bankerTotal) {
    case 7:
        return false;

    case 6:
        if (hitCardValue == 6 || hitCardValue == 7) {
            return true;
        } else {
            return false;
        }

    case 5:
        if (hitCardValue >= 4 && hitCardValue <= 7) {
            return true;
        } else {
            return false;
        }

    case 4:
        if (hitCardValue >= 2 && hitCardValue <= 7) {
            return true;
        } else {
            return false;
        }

    case 3:
        if (hitCardValue != 8) {
            return true;
        } else {
            return false;
        }

    default:
        return false;
    }
}


