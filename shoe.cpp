/*
 * shoe.cpp
 *
 *  Created on: Aug 28, 2016
 *      Author: jeff
 */

#include "shoe.h"
#include <algorithm>
#include <random>
#include <iterator>

namespace {
std::vector<PlayingCard> deck = {
        PlayingCard("Ah", 1), PlayingCard("2h", 2), PlayingCard("3h", 3),
        PlayingCard("4h", 4), PlayingCard("5h", 5), PlayingCard("6h", 6),
        PlayingCard("7h", 7), PlayingCard("8h", 8), PlayingCard("9h", 9),
        PlayingCard("Th", 10), PlayingCard("Jh", 10), PlayingCard("Qh", 10),
        PlayingCard("Kh", 10),

        PlayingCard("Ac", 1), PlayingCard("2c", 2), PlayingCard("3c", 3),
        PlayingCard("4c", 4), PlayingCard("5c", 5), PlayingCard("6c", 6),
        PlayingCard("7c", 7), PlayingCard("8c", 8), PlayingCard("9c", 9),
        PlayingCard("Tc", 10), PlayingCard("Jc", 10), PlayingCard("Qc", 10),
        PlayingCard("Kc", 10),

        PlayingCard("As", 1), PlayingCard("2s", 2), PlayingCard("3s", 3),
        PlayingCard("4s", 4), PlayingCard("5s", 5), PlayingCard("6s", 6),
        PlayingCard("7s", 7), PlayingCard("8s", 8), PlayingCard("9s", 9),
        PlayingCard("Ts", 10), PlayingCard("Js", 10), PlayingCard("Qs", 10),
        PlayingCard("Ks", 10),

        PlayingCard("Ad", 1), PlayingCard("2d", 2), PlayingCard("3d", 3),
        PlayingCard("4d", 4), PlayingCard("5d", 5), PlayingCard("6d", 6),
        PlayingCard("7d", 7), PlayingCard("8d", 8), PlayingCard("9d", 9),
        PlayingCard("Td", 10), PlayingCard("Jd", 10), PlayingCard("Qd", 10),
        PlayingCard("Kd", 10),
};
}

PlayingCard Shoe::Cut_Card("CUT_CARD", 0);

Shoe::Shoe(const int numberOfDecks)
{
    for (int i = 0; i < numberOfDecks; i++) {
        _shoe.insert(end(_shoe), begin(deck), end(deck));
    }
}

void Shoe::shuffle(const int numberOfShuffles)
{
    std::mt19937_64 r(static_cast<uint64_t>(time(nullptr)));
    for (int i = 0; i < numberOfShuffles; i++) {
        std::shuffle(begin(_shoe), end(_shoe), r);
    }
}

PlayingCard& Shoe::deal()
{
    if ((*_pos).getId() == Shoe::Cut_Card.getId()) {
        _pos = _shoe.erase(_pos);
        return Shoe::Cut_Card;
    } else {
        return *(_pos++);
    }
}

void Shoe::discard(int numberToDiscard)
{
    while (_pos != end(_shoe) && numberToDiscard-- > 0) {
        ++_pos;
    }
}

void Shoe::insertCutCard(const int cutCardPosition)
{
    int actualPosition = _shoe.size() - cutCardPosition;
    _shoe.insert(begin(_shoe) + actualPosition, Shoe::Cut_Card);
    _pos = begin(_shoe);
}
