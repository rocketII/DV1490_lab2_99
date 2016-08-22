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

int main(int argc, char** argv)
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
//DBG : working
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
    for (int i = 0; i < 13 ; ++i)
    {
        Card a(suits[0],values[i ],names[i]); Card* aPtr = &a;
        Card b(suits[1],values[i ],names[i]); Card* bPtr = &b;
        Card c(suits[2],values[i ],names[i]); Card* cPtr = &c;
        Card d(suits[3],values[i ],names[i]); Card* dPtr = &d;
        cardDeck.push(aPtr);
        cardDeck.push(bPtr);
        cardDeck.push(cPtr);
        cardDeck.push(dPtr);

    }
}
//DBG : ready 4 test
void shuffleCardDeck(Stack<Card*> &cardDeck)
{
	// blanda korten i kortleken
	// Tips! Plocka ut alla kort från kortleken (CardDeck)
	// och blanda dem för att därefter placera tillbaka korten i kortleken (CardDeck)
    Card* ptr[52] = {nullptr};
    int countDown=52;
    for (int p = 0; p < 52; p++)
    {
        ptr[p] = cardDeck.pop();
    }
    for (int i = 0; i < 52 ; ++i)
    {
        if(ptr[(((int)rand) % 52)] != nullptr)
        {
            cardDeck.push(ptr[((int)rand)%52]);
            countDown--;
        }

    }
    bool shallContinue = true;

    while (shallContinue)
    {
        if(ptr[((int)rand)%52] != nullptr)
        {
            cardDeck.push(ptr[((int)rand)%52]);
            countDown--;
        }
        if(countDown == 0)
        {
            shallContinue = false;
        }
    }
}
//DBG : ready 4 test
void addPlayers(CircularDoubleDirectedList<Player> &players)
{
	// låt användaren mata in antalet spelare som ska vara med och
	// lös in namnen på spelarna och placera spelarna i listan (players)
    int playersPc=0;
    string name;
	cout << "Number of Pc:s(input integers only)? >>>"<<endl;
    cin >> playersPc;
    for (int count =0; count < playersPc; count++)
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
        Player* currentPC = &players.currentItem();
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
    cout << "Som of pile"<< cardSum<<endl;
	// presentera/skriv ut spelarens namn och hand mha toString()
    cout << "Player: "<< players.currentItem().getName()<<endl;
    cout << "At hand: \n"<< players.currentItem().getHandAsString()<<endl;
	// låt spelaren mata in numret (1, 2 eller 3) på det kort spelaren ska placera på korthögen (cardPile)
    cout << "enter 1 or 2 or 3"<< endl;
    int choice = 0;
    cin >> choice;
	// ta det kort spelaren anger
    cardPile.push(players.currentItem().returnCard(choice));
	// och ge spelaren ett nytt kort från kortleken (cardDeck)
    players.currentItem().addCard(cardDeck.pop());
	// placera det kort spelaren lämnat på korthögen och hantera konsekvensen av kortet på korthögen
    /*
      dam och kung ökar värdet på korthögen med 10
      knekt sätter korthögens värde till 99
      10 minskar korthögens värde med 10
      9 bibehåller korthögens värde men vänder håll på turordningen för spelarna
      8 bibehåller korthögensvärde
      ess ökar korthögens värde med 1
      övriga kort ökar korthögens värde kortets värde (ex-vis en 5:a ökar korthögens värde med 5)*/
    int values[] = { 1, 2, 3, 4, 5, 6, 7, 0, 0, -10, 99, 10, 10 };
    switch(cardPile.peek()->getValue())
    {
        case 1 :
            cardSum += 1;
            break;
        case 2 :
            cardSum += 2;
            break;
        case 3 :
            cardSum += 3;
            break;
        case 4 :
            cardSum += 4;
            break;
        case 5 :
            cardSum += 5;
            break;
        case 6 :
            cardSum += 6;
            break;
        case 7 :
            cardSum += 7;
            break;
        case 0 :
            if(cardPile.peek()->getName() == "9")
                players.changeDirection();
            break;
        case -10 :
            cardSum -= 10;
            break;
        case 99 :
            cardSum += 99;
            break;
        case 10 :
            cardSum += 10;
            break;
    }
    // förändra värdet för korthögen och ändra eventuellt turordningen för spelarna

    // avgör om spelet ska fortsätta eller ej (beroende på värdet på korthögen)
	// och returnera detta 
	if(cardSum > 99)
        continuePlay= false;
	return continuePlay;
}

//DBG : ready 4 test
void cardsFromPileBackToDeck(Stack<Card*> &cardDeck, Stack<Card*> &cardPile)
{
	// ta alla kort från korthögen (cardPile)
	// och placeras i kortleken (cardDeck)
    for (int i = 0; !cardPile.isEmpty() ; ++i)
    {
        cardDeck.push(cardPile.pop());
    }
}

//DBG : ready 4 test
void returnCardsToDeck(Player& loosingPlayer, Stack<Card*> &cardDeck)
{
    Card* holdIt = nullptr;
	// spelarens kort återlämnas och placeras i korteken
    int stop = loosingPlayer.getCurrentNrOfCards();
    for (int i = 0; i < stop ; ++i)
    {
        holdIt = loosingPlayer.returnCard(i);
        if(holdIt != nullptr)
            cardDeck.push(holdIt);
    }
}