#include "Player.h"
#include "CircularDoubleDirectedList.h"
#include "Card.h"
#include "Stack.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const int SIZE = 52;

void makeCardDeck(Stack<Card*> &cardDeck);
void shuffleCardDeck(Stack<Card*> &cardDeck);
void addPlayers(CircularDoubleDirectedList<Player> &players);
void dealCards(Stack<Card*> &cardDeck, CircularDoubleDirectedList<Player> &players);
bool handleCurrentPlayer(Stack<Card*> &cardDeck, CircularDoubleDirectedList<Player> &players, int &cardSum, Stack<Card*> &cardPile);
void cardsFromPileBackToDeck(Stack<Card*> &cardDeck, Stack<Card*> &cardPile);
void returnCardsToDeck(Player& loosingPlayer, Stack<Card*> &cardDeck);

int main(int argc, char argv[])
{
	srand((unsigned)time(NULL));
	string dummy;
	string playerName;
	int cardSum = 0;
	Stack<Card*> cardDeck;
	Stack<Card*> cardPile;

	makeCardDeck(cardDeck);
	shuffleCardDeck(cardDeck);

	CircularDoubleDirectedList<Player> players;

	addPlayers(players);
	std::cout << endl;
	dealCards(cardDeck, players);

	while (players.size() > 1)
	{

		cout << "The number of players are " << players.size() << endl;


		cardSum = 0;
		while (handleCurrentPlayer(cardDeck, players, cardSum, cardPile));


		std::cout << endl << endl << players.currentItem().getName() << " lost! " << endl << endl << endl;

		getline(cin, dummy);
		returnCardsToDeck(players.currentItem(), cardDeck);


		players.remove(players.currentItem());

		cardsFromPileBackToDeck(cardDeck, cardPile);
		shuffleCardDeck(cardDeck);
	}

	cout << endl << endl << "The winner is " << players.currentItem().getName() << endl;

	return 0;
}

void makeCardDeck(Stack<Card*> &cardDeck)
{
	string suits[] = { "Harts", "Spades", "Diamonds", "Clubs" };
	string names[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Knight", "Queen", "King" };
	int values[] = { 1, 2, 3, 4, 5, 6, 7, 0, 0, -10, 99, 10, 10 };

	// skapa korten f�r kortleken (cardDeck) genom att anv�nda f�lten/arrayerna suits, names, values
	
}

void shuffleCardDeck(Stack<Card*> &cardDeck)
{
	// blanda korten i kortleken
	// Tips! Plocka ut alla kort fr�n kortleken (CardDeck) 
	// och blanda dem f�r att d�refter placera tillbaka korten i kortleken (CardDeck)
	
}

void addPlayers(CircularDoubleDirectedList<Player> &players)
{
	// l�t anv�ndaren mata in antalet spelare som ska vara med och
	// l�s in namnen p� spelarna och placera spelarna i listan (players)
	
}

void dealCards(Stack<Card*> &cardDeck, CircularDoubleDirectedList<Player> &players)
{
	// dela ut 3 kort var fr�n kortleken (cardDeck) till spelarna (players)

}

bool handleCurrentPlayer(Stack<Card*> &cardDeck, CircularDoubleDirectedList<Player> &players, int &cardSum, Stack<Card*> &cardPile)
{
	bool continuePlay = true;
	// presentera/skriv ut v�rdet f�r korth�gen
	// presentera/skriv ut spelarens namn och hand mha toString()
	// l�t spelaren mata in numret (1, 2 eller 3) p� det kort spelaren ska placera p� korth�gen (cardPile)
	// ta det kort spelaren anger
	// och ge spelaren ett nytt kort fr�n korteken (cardDeck)
	// placera det kort spelaren l�mnat p� korth�gen och hantera konsekvensen av kortet p� korth�gen
	// f�r�ndra v�rdet f�r korth�gen och �ndra eventuellt turordningen f�r spelarna 
	// avg�r om spelet ska forts�tta eller ej (beroende p� v�rdet p� korth�gen)
	// och returnera detta 
	
	return continuePlay;
}
void cardsFromPileBackToDeck(Stack<Card*> &cardDeck, Stack<Card*> &cardPile)
{
	// ta alla kort fr�n korth�gen (cardPile)
	// och placeras i kortleken (cardDeck)
}

void returnCardsToDeck(Player& loosingPlayer, Stack<Card*> &cardDeck)
{
	// spelarens kort �terl�mnas och placeras i korteken
	
}