#include "Card.h"
#include <iostream>
#include <sstream>

using namespace std;

Card::Card()
{
	this->suit = "";
	this->value = 0;
	this->name = "";
}

Card::Card(std::string suit, int value, string name)
{
	this->suit = suit;
	this->value = value;
	this->name = name;
}

Card::~Card()
{
}

int Card::getValue() const
{
	return this->value;
}

string Card::getSuit() const
{
	return this->suit;
}

string Card::getName() const
{
	return this->name;
}

string Card::toString() const
{
	stringstream ss;
    ss << this->suit << " "<< this->name;
	return ss.str();
}