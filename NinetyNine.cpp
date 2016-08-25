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
// ready 4 testing
int main(int argc, char** argv)
{
    //maximum ** players
	srand((unsigned)time(NULL));
	string dummy;
	string playerName;
	int cardSum = 0;
	Stack<Card*> cardDeck;
	Stack<Card*> cardPile;
	makeCardDeck(cardDeck); //works
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
//DBG : tested, stack dosen't seem to work here, card values gets modified. Using CLion as for DBG.
void makeCardDeck(Stack<Card*> &cardDeck)
{
    //varje kort
	//string suits[] = { "Harts", "Spades", "Diamonds", "Clubs" };
    string suits[] = { "Hjärter", "Spader", "Ruter", "Klöver" };
	//string names[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Knight", "Queen", "King" };
    string names[] = { "Ess", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Knekt", "Drottning", "Kung" };
	int values[] = { 1, 2, 3, 4, 5, 6, 7, 0, 0, -10, 99, 10, 10 };

	// skapa korten för kortleken (cardDeck) genom att använda fälten/arrayerna suits, names, values

    //Card* a= nullptr, *b= nullptr, *c= nullptr, *d= nullptr;
    /*       -------------------|| Bug  creating new cards dynamically overrites old entries ||----------------------
    Card* array[52]={nullptr};
    for (int i = 0, arrayIndexer=0; i < 13  ; ++i, arrayIndexer += 4)
    {
        array[arrayIndexer] = new Card(suits[0],values[i],names[i]);
        array[arrayIndexer+1] = new Card(suits[1],values[i],names[i]);
        array[arrayIndexer+2] = new Card(suits[2],values[i],names[i]);
        array[arrayIndexer+3] = new Card(suits[3],values[i],names[i]);
        //DBG only
        cout<<"array[arrayIndexer]: adress: "<<array[arrayIndexer]<<" "<< array[arrayIndexer]->toString()<<" "<<array[arrayIndexer]->getValue()<<endl;
        cout<<"array[arrayIndexer+1]: adress: "<<array[arrayIndexer+1]<<" "<< array[arrayIndexer+1]->toString()<<" "<<array[arrayIndexer+1]->getValue()<<endl;
        cout<<"array[arrayIndexer+2]: adress: "<<array[arrayIndexer+2]<<" "<< array[arrayIndexer+2]->toString()<<" "<<array[arrayIndexer+2]->getValue()<<endl;
        cout<<"array[arrayIndexer+3]: adress: "<<array[arrayIndexer+2]<<" "<< array[arrayIndexer+2]->toString()<<" "<<array[arrayIndexer+2]->getValue()<<endl;
        cout<<"\nNext iteration!-----\a--------------------------------------"<<endl;
        //DBG end
        cardDeck.push(array[arrayIndexer]); //.
        cardDeck.push(array[arrayIndexer+1]); //
        cardDeck.push(array[arrayIndexer+2]); //
        cardDeck.push(array[arrayIndexer+3]); //
        delete array[arrayIndexer];
        array[arrayIndexer] = nullptr;
        delete array[arrayIndexer+1];
        array[arrayIndexer+1] = nullptr;
        delete array[arrayIndexer+2];
        array[arrayIndexer+2] = nullptr;
        delete array[arrayIndexer+3];
        array[arrayIndexer+3] = nullptr;
    }
     */
    cout << "\n----------------------------------"<<endl;
    for (int i = 0; i < 52; i++)
    {
        cout<< cardDeck.peek()->toString()<<" "<<cardDeck.peek()->getValue()<<endl;
        cardDeck.pop();
    }

}
//DBG : ready 4 test
void shuffleCardDeck(Stack<Card*> &cardDeck)
{
	// blanda korten i kortleken
	// Tips! Plocka ut alla kort från kortleken (CardDeck)
	// och blanda dem för att därefter placera tillbaka korten i kortleken (CardDeck)
    Card* ptr[52] ={nullptr};
    Card* swap = nullptr;
    int countDown=52;
    int random = rand()% 52;
    int randomII = ((rand()% 52 + rand()%52)%52);
    //fill ptr with Card*
    for (int p = 0; p < 52; p++) // fill a array with card *
    {
        ptr[p] = cardDeck.pop();
        cout <<"suit: "<< ptr[p]->getSuit()<<" name:"<<ptr[p]->getName()<<" value: "<< ptr[p]->getValue()<< endl;
    }//end DBG

    bool shallContinue = true;
    Card* holder= nullptr;
    Card* holderII= nullptr;
    while (shallContinue)
    {
        random = rand()% 52;
        randomII = ((rand()% 52 + rand()%52)%52);
        if((random != randomII))
        {
            swap = ptr[random];
            ptr[random] = ptr[randomII];
            ptr[randomII] = swap;
            holder = new Card(*ptr[random]);
            holderII = new Card(*ptr[randomII]);
            cardDeck.push(holder);
            cardDeck.push(holderII);
            delete holder;
            delete holderII;
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
    Player* b;
    for (int count =0; count < playersPc; count++)
    {
        cout << "\nName: "<<endl;
        getline(cin, name);
        b=new Player(name);
        players.add(*b);
        delete b;
    }
}
//DBG : ready 4 test
void dealCards(Stack<Card*> &cardDeck, CircularDoubleDirectedList<Player> &players)
{
	// dela ut 3 kort var från kortleken (cardDeck) till spelarna (players)
    Player* currentPC;
    for (int i = 0; i < 3 ; ++i)
    {
        currentPC = &players.currentItem();
        currentPC->addCard(cardDeck.pop());
        currentPC->addCard(cardDeck.pop());
        currentPC->addCard(cardDeck.pop());
        players.move();
    }
}
//DBG : ready 4 testing
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