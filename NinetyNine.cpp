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
//DBG : implementing
void makeCardDeck(Stack<Card*> &cardDeck)
{
    //varje kort
	string suits[] = { "Harts", "Spades", "Diamonds", "Clubs" };
	string names[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Knight", "Queen", "King" };
	int values[] = { 1, 2, 3, 4, 5, 6, 7, 0, 0, -10, 99, 10, 10 };
//
	// skapa korten för kortleken (cardDeck) genom att använda fälten/arrayerna suits, names, values
    /*
      dam och kung ökar värdet på korthögen med 10
      knekt sätter korthögens värde till 99
      10 minskar korthögens värde med 10
      9 bibehåller korthögens värde men vänder håll på turordningen för spelarna
      8 bibehåller korthögensvärde
      ess ökar korthögens värde med 1
      övriga kort ökar korthögens värde kortets värde (ex-vis en 5:a ökar korthögens värde med 5)*/
    for (int i = 0; i < 52 ; ++i)
    {
        cardDeck.push(Card(suits[0],values[i % 13],names[i % 13]));
        cardDeck.push(Card(suits[1],values[i % 13],names[i % 13]));
        cardDeck.push(Card(suits[2],values[i % 13],names[i % 13]));
        cardDeck.push(Card(suits[3],values[i % 13],names[i % 13]));

    }
}
//DBG : implementing
void shuffleCardDeck(Stack<Card*> &cardDeck)
{
	// blanda korten i kortleken
	// Tips! Plocka ut alla kort från kortleken (CardDeck)
	// och blanda dem för att därefter placera tillbaka korten i kortleken (CardDeck)
	
}
//DBG : implementing
void addPlayers(CircularDoubleDirectedList<Player> &players)
{
	// låt användaren mata in antalet spelare som ska vara med och
	// lös in namnen på spelarna och placera spelarna i listan (players)
    int playersPc=0;
    string name;
	cout << "Number of Pc:s(input integers only)? >>>"<<endl;
    cin >> playersPc;
    for (int count =0; count < players; count++)
    {
        cout << "\nName: "<<endl;
        getline(cin, name);
        players.add(name);
    }
}
//DBG : ready 4 test
void dealCards(Stack<Card*> &cardDeck, CircularDoubleDirectedList<Player> &players)
{
	// dela ut 3 kort var från kortleken (cardDeck) till spelarna (players)
    for (int i = 0; i < 3 ; ++i)
    {
        Player* currentPC = players.currentItem();
        currentPC->addCard(cardDeck.pop());
        currentPC->addCard(cardDeck.pop());
        currentPC->addCard(cardDeck.pop());
        players.move();
    }

}
//DBG : implementing
bool handleCurrentPlayer(Stack<Card*> &cardDeck, CircularDoubleDirectedList<Player> &players, int &cardSum, Stack<Card*> &cardPile)
{
	bool continuePlay = true;
	// presentera/skriv ut värdet för korthögen

	// presentera/skriv ut spelarens namn och hand mha toString()

	// låt spelaren mata in numret (1, 2 eller 3) på det kort spelaren ska placera på korthögen (cardPile)

	// ta det kort spelaren anger

	// och ge spelaren ett nytt kort från korteken (cardDeck)

	// placera det kort spelaren lämnat på korthögen och hantera konsekvensen av kortet på korthögen

    // förändra värdet för korthögen och ändra eventuellt turordningen för spelarna

    // avgör om spelet ska fortsätta eller ej (beroende på värdet på korthögen)
	// och returnera detta 
	
	return continuePlay;
}

//DBG : implementing
void cardsFromPileBackToDeck(Stack<Card*> &cardDeck, Stack<Card*> &cardPile)
{
	// ta alla kort från korthögen (cardPile)
	// och placeras i kortleken (cardDeck)

}

//DBG : implementing
void returnCardsToDeck(Player& loosingPlayer, Stack<Card*> &cardDeck)
{
	// spelarens kort återlämnas och placeras i korteken
	
}