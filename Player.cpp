#include "Player.h"
#include <iostream>
#include <sstream>
using namespace std;

Player::Player()
{
	this->name = "";
	this->currentNrOfCards = 0;
	for (int i = 0; i < 3; i++)
		hand[i] = nullptr;
}

Player::Player(std::string name)
{
	this->name = name;
	this->currentNrOfCards = 0;
	for (int i = 0; i < 3; i++)
		hand[i] = nullptr;
}

Player::Player(const Player& other)
{
	this->name = other.name;
	this->currentNrOfCards = other.currentNrOfCards;
	for (int i = 0; i < 3; i++)
	{
		hand[i] = nullptr;
		if (other.hand[i] != nullptr)
			this->hand[i] = new Card(*other.hand[i]);
	}
}

Player::~Player()
{
	for (int i = 0; i < 3; i++)
		delete hand[i];
}



string Player::getHandAsString() const
{
	stringstream converter;
	for (int i=0; i<3; i++)
	{
		converter << "Card " << (i + 1) << ": " << this->hand[i]->toString()<< endl;
	}
	return converter.str();
}

bool Player::addCard(Card* card)
{
	if (this->currentNrOfCards == 3)
		throw "Exception: hand full";
	bool added = false;
	for (int i = 0; i < 3 && !added; i++)
	{
		if (this->hand[i] == nullptr)
		{
			hand[i] = card;
			added = true;
			this->currentNrOfCards++;
		}
	}
	
	return added;
}

Card* Player::returnCard(int posOfCardToreturn)
{
	Card* temp = this->hand[posOfCardToreturn];
	this->hand[posOfCardToreturn] = nullptr;
	if (temp != nullptr)
		this->currentNrOfCards--;
	return temp;

}

string Player::getName() const
{
	return this->name;
}

int Player::getCurrentNrOfCards() const
{
	return this->currentNrOfCards;
}

bool Player::operator==(const Player &player) const
{
	return (player.name == this->name);
}

bool Player::operator!=(const Player &player) const
{
	return (player.name != this->name);
}
