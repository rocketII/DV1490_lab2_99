#ifndef CARD_H
#define CARD_H
#include <string>

using namespace std;

class Card
{
private:
	int value; // v�rde
	string suit; // f�rg
	string name; // exempelvis ess, dam, 2
public:
	Card();
	Card(string suit, int value, string name);
	virtual ~Card();
	int getValue() const;
	string getSuit() const;
	string getName() const;
	string toString() const;
};

#endif