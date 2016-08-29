/*
 * playing_card.h
 *
 *  Created on: Aug 28, 2016
 *      Author: jeff
 */

#ifndef PLAYING_CARD_H_
#define PLAYING_CARD_H_

#include <string>

class PlayingCard {
public:
	PlayingCard(std::string id, int value): _id(id), _value(value) {}

	const std::string& getId() const { return _id; }
	int getValue() const { return _value; }

private:
	std::string _id;
	int _value;
};


#endif /* PLAYING_CARD_H_ */
