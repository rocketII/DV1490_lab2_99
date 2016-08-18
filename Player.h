#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"

using namespace std;

class Player
{
private:
	Card* hand[3];
	string name;
	int currentNrOfCards;
public:
	Player();
	Player(string name); 
	Player(const Player& other);
	virtual ~Player();
	string getHandAsString() const;
	bool addCard(Card* card); 
	Card* returnCard(int posOfCardToreturn); 
	string getName() const;
	int getCurrentNrOfCards() const;
	bool operator==(const Player &player) const;
	bool operator!=(const Player &player) const;
};

#endif