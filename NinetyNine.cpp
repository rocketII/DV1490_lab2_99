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
    //fix leaftover allocations.
    while (!cardDeck.isEmpty())
    {
        delete cardDeck.pop();
    }
    while (!cardPile.isEmpty())
    {
        delete cardPile.pop();
    }
	return 0;
}
//DBG : works,
void makeCardDeck(Stack<Card*> &cardDeck)
{
    //varje kort
	//string suits[] = { "Harts", "Spades", "Diamonds", "Clubs" };
    string suits[] = { "Hjärter", "Spader", "Ruter", "Klöver" };
	//string names[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Knight", "Queen", "King" };
    string names[] = { "Ess", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Knekt", "Drottning", "Kung" };
	int values[] = { 1, 2, 3, 4, 5, 6, 7, 0, 0, -10, 99, 10, 10 };

	// skapa korten för kortleken (cardDeck) genom att använda fälten/arrayerna suits, names, values
    //då mitt problem ej är löst har jag en fullösning. Den funkar dock :)
    Card* array[SIZE]={nullptr};
    int i = 0, k=0;
    while( k < SIZE)
    {
        array[k] =  new Card(suits[0],values[i],names[i%13]);k++;
        array[k] =  new Card(suits[1],values[i],names[i%13]);k++;
        array[k] =  new Card(suits[2],values[i],names[i%13]);k++;
        array[k] =  new Card(suits[3],values[i],names[i%13]);k++;
        i++;
    }
    k=0;i=0;


    for (int j = 0; j < SIZE ; ++j)
    {
        cardDeck.push(array[j]);
    }
    //for (int j = 0; j < SIZE ; ++j)
    {
        //might cause problems with the nodes. better do delete Cards later.
        //delete array[j];
    }

   /* DBG ONLY
    for (int i = 0; i < SIZE; i++)
    {
        cout<< cardDeck.peek()->toString()<<" "<<cardDeck.peek()->getValue()<<endl;
        cardDeck.pop();
    } END DBG*/
    //code below candidate for deletion.
    //           | | | |
    //           v v v v
    //Card* a= nullptr, *b= nullptr, *c= nullptr, *d= nullptr; <---old fix which is now obsolete.
    /*       -------------------|| Bug  creating new cards dynamically overrites old entries, new reuse reserved memory ||----------------------
    Card* array[SIZE]={nullptr};
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
    cout << "\n----------------------------------"<<endl;//while using DBG
    /*for (int i = 0; i < 52; i++)   <--- dbg print.
    {
        cout<< cardDeck.peek()->toString()<<" "<<cardDeck.peek()->getValue()<<endl;
        cardDeck.pop();
    }
    */
}
//DBG : works (old bug yet to be solved)
// shuffleCardsDeck never deletes cards.
void shuffleCardDeck(Stack<Card*> &cardDeck)
{
	// Blanda korten i kortleken
	// Tips! Plocka ut alla kort från kortleken (CardDeck)
	// och blanda dem för att därefter placera tillbaka korten i kortleken (CardDeck)
    Card** ptr=new Card*[SIZE];
    Card* swap = nullptr;
    int nrOfCardsInDeck=0;
    int p = 0;


    //fill ptr with Card*
    while(!cardDeck.isEmpty()) // fill a array with card *
    {
        ptr[p] = cardDeck.pop();
        //cout <<"suit: "<< ptr[p]->getSuit()<<" name:"<<ptr[p]->getName()<<" value: "<< ptr[p]->getValue()<< endl;
        nrOfCardsInDeck++;p++;
    }//end DBG
    //second init
    int countDown=nrOfCardsInDeck;
    int random = rand()% nrOfCardsInDeck;
    int randomII = ((rand()% nrOfCardsInDeck + rand()%nrOfCardsInDeck)%nrOfCardsInDeck);
    //cout << "\n------------------------next!!!--------------------------\n";
    bool shallContinue = true;

    //shuffle pointers
    while (shallContinue)
    {
        random = rand()% nrOfCardsInDeck;
        randomII = ((rand()% nrOfCardsInDeck + rand()%nrOfCardsInDeck)%nrOfCardsInDeck);
        if((random != randomII))
        {
            swap = ptr[random];
            ptr[random] = ptr[randomII];
            ptr[randomII] = swap;
            countDown--;
        }
        //shuffle done push all the pointer
        if(countDown == 0)
        {
            shallContinue = false;
            for (int j = 0; j < nrOfCardsInDeck ; ++j)
            {
                cardDeck.push(ptr[j]);
            }
            //DBG output
            /*
            for (int i = 0; i < nrOfCardsInDeck; i++)
            {
                cout<<"#"<<i+1<<" : "<< cardDeck.peek()->toString()<<" value:"<<cardDeck.peek()->getValue();
                cout  <<" address: "<< cardDeck.pop()<<endl;
            }*/
        }

    }
    for (int i = 0; i < nrOfCardsInDeck ; ++i)
    {
        //delete ptr[i];
    }
    delete[] ptr;
}
//DBG : works
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
        fflush(stdin);
        cout << "\nName: "<<'\n';
        fflush(stdin);
        cin >> name;
        fflush(stdin);
        b=new Player(name);
        players.add(*b);
        delete b;
    }
}
//DBG : seems to work fine
void dealCards(Stack<Card*> &cardDeck, CircularDoubleDirectedList<Player> &players)
{
	// dela ut 3 kort var från kortleken (cardDeck) till spelarna (players)
    Player* currentPC;
    for (int i = 0; i < players.size() ; ++i)
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
    // presentera/skriv ut värdet för korthögen
    // presentera/skriv ut spelarens namn och hand mha toString()
    // låt spelaren mata in numret (1, 2 eller 3) på det kort spelaren ska placera på korthögen (cardPile)
    // ta det kort spelaren anger
    // och ge spelaren ett nytt kort från kortleken (cardDeck)
    // placera det kort spelaren lämnat på korthögen och hantera konsekvensen av kortet på korthögen
    // förändra värdet för korthögen och ändra eventuellt turordningen för spelarna
    // avgör om spelet ska fortsätta eller ej (beroende på värdet på korthögen)
    // och returnera detta

    cout << "Sum of pile: "<< cardSum<<endl;
    cout << "Player: "<< players.currentItem().getName()<<endl;
    cout << "At hand: \n"<< players.currentItem().getHandAsString()<<endl;
    cout << "enter 1 or 2 or 3 (or 9 for selfdestruct)"<< endl;
    int choice = 0;
    cin >> choice;
    --choice;
    if((choice+1) == 9 )
        return false;
    cardPile.push(players.currentItem().returnCard(choice));
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
            cardSum = 99;
            break;
        case 10 :
            cardSum += 10;
            break;
    }
    if(cardSum > 99)
        return false;
    players.currentItem().addCard(cardDeck.pop());
    /*
      dam och kung ökar värdet på korthögen med 10
      knekt sätter korthögens värde till 99
      10 minskar korthögens värde med 10
      9 bibehåller korthögens värde men vänder håll på turordningen för spelarna
      8 bibehåller korthögensvärde
      ess ökar korthögens värde med 1
      övriga kort ökar korthögens värde kortets värde (ex-vis en 5:a ökar korthögens värde med 5)*/

    players.move();

	return true;
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

///////Dev comments and details ------------------------------------------------------------------------

/*
 *   memleak fixed and game working for two players. But krasch with signal 11(sigsegfault) when a player of 3 or more loses .
 *
 *   valgrind IO:
The number of players are 2.
 Sum of pile: 99
Player: v
At hand:
Card 1: Hjärter Ess
Card 2: Ruter Ess
Card 3: Klöver 2

enter 1 or 2 or 3 (or 9 for selfdestruct)
1


v lost!


==28883== Invalid read of size 8
==28883==    at 0x4EF3240: std::string::size() const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.20)
==28883==    by 0x403C99: __gnu_cxx::__enable_if<std::__is_char<char>::__value, bool>::__type std::operator==<char>(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) (basic_string.h:2514)
==28883==    by 0x403B44: Player::operator==(Player const&) const (Player.cpp:92)
==28883==    by 0x4068FD: CircularDoubleDirectedList<Player>::operator==(Player const&) (CircularDoubleDirectedList.h:467)
==28883==    by 0x405E83: CircularDoubleDirectedList<Player>::remove(Player&) (CircularDoubleDirectedList.h:349)
==28883==    by 0x403F26: main (NinetyNine.cpp:52)
==28883==  Address 0x5a060f0 is 32 bytes inside a block of size 64 free'd
==28883==    at 0x4C2A360: operator delete(void*) (vg_replace_malloc.c:507)
==28883==    by 0x405DD6: CircularDoubleDirectedList<Player>::remove(Player&) (CircularDoubleDirectedList.h:323)
==28883==    by 0x403F26: main (NinetyNine.cpp:52)
==28883==
==28883== Invalid read of size 8
==28883==    at 0x4EF3243: std::string::size() const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.20)
==28883==    by 0x403C99: __gnu_cxx::__enable_if<std::__is_char<char>::__value, bool>::__type std::operator==<char>(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) (basic_string.h:2514)
==28883==    by 0x403B44: Player::operator==(Player const&) const (Player.cpp:92)
==28883==    by 0x4068FD: CircularDoubleDirectedList<Player>::operator==(Player const&) (CircularDoubleDirectedList.h:467)
==28883==    by 0x405E83: CircularDoubleDirectedList<Player>::remove(Player&) (CircularDoubleDirectedList.h:349)
==28883==    by 0x403F26: main (NinetyNine.cpp:52)
==28883==  Address 0x5a06000 is 0 bytes inside a block of size 26 free'd
==28883==    at 0x4C2A360: operator delete(void*) (vg_replace_malloc.c:507)
==28883==    by 0x403866: Player::~Player() (Player.cpp:34)
==28883==    by 0x4068D1: CircularDoubleDirectedList<Player>::Node::~Node() (CircularDoubleDirectedList.h:26)
==28883==    by 0x405DCE: CircularDoubleDirectedList<Player>::remove(Player&) (CircularDoubleDirectedList.h:323)
==28883==    by 0x403F26: main (NinetyNine.cpp:52)
==28883==
==28883== Invalid read of size 8
==28883==    at 0x4EF3240: std::string::size() const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.20)
==28883==    by 0x403CB9: __gnu_cxx::__enable_if<std::__is_char<char>::__value, bool>::__type std::operator==<char>(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) (in /root/.CLion12/system/cmake/generated/7eeba64d/7eeba64d/Debug0/DV1490_lab2_99)
==28883==    by 0x403B44: Player::operator==(Player const&) const (Player.cpp:92)
==28883==    by 0x4068FD: CircularDoubleDirectedList<Player>::operator==(Player const&) (CircularDoubleDirectedList.h:467)
==28883==    by 0x405E83: CircularDoubleDirectedList<Player>::remove(Player&) (CircularDoubleDirectedList.h:349)
==28883==    by 0x403F26: main (NinetyNine.cpp:52)
==28883==  Address 0x5a060f0 is 32 bytes inside a block of size 64 free'd
==28883==    at 0x4C2A360: operator delete(void*) (vg_replace_malloc.c:507)
==28883==    by 0x405DD6: CircularDoubleDirectedList<Player>::remove(Player&) (CircularDoubleDirectedList.h:323)
==28883==    by 0x403F26: main (NinetyNine.cpp:52)
==28883==
==28883== Invalid read of size 8
==28883==    at 0x4EF3243: std::string::size() const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.20)
==28883==    by 0x403CB9: __gnu_cxx::__enable_if<std::__is_char<char>::__value, bool>::__type std::operator==<char>(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) (in /root/.CLion12/system/cmake/generated/7eeba64d/7eeba64d/Debug0/DV1490_lab2_99)
==28883==    by 0x403B44: Player::operator==(Player const&) const (Player.cpp:92)
==28883==    by 0x4068FD: CircularDoubleDirectedList<Player>::operator==(Player const&) (CircularDoubleDirectedList.h:467)
==28883==    by 0x405E83: CircularDoubleDirectedList<Player>::remove(Player&) (CircularDoubleDirectedList.h:349)
==28883==    by 0x403F26: main (NinetyNine.cpp:52)
==28883==  Address 0x5a06000 is 0 bytes inside a block of size 26 free'd
==28883==    at 0x4C2A360: operator delete(void*) (vg_replace_malloc.c:507)
==28883==    by 0x403866: Player::~Player() (Player.cpp:34)
==28883==    by 0x4068D1: CircularDoubleDirectedList<Player>::Node::~Node() (CircularDoubleDirectedList.h:26)
==28883==    by 0x405DCE: CircularDoubleDirectedList<Player>::remove(Player&) (CircularDoubleDirectedList.h:323)
==28883==    by 0x403F26: main (NinetyNine.cpp:52)
==28883==
==28883== Invalid read of size 8
==28883==    at 0x4EF33E0: std::string::data() const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.20)
==28883==    by 0x403CD7: __gnu_cxx::__enable_if<std::__is_char<char>::__value, bool>::__type std::operator==<char>(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) (in /root/.CLion12/system/cmake/generated/7eeba64d/7eeba64d/Debug0/DV1490_lab2_99)
==28883==    by 0x403B44: Player::operator==(Player const&) const (Player.cpp:92)
==28883==    by 0x4068FD: CircularDoubleDirectedList<Player>::operator==(Player const&) (CircularDoubleDirectedList.h:467)
==28883==    by 0x405E83: CircularDoubleDirectedList<Player>::remove(Player&) (CircularDoubleDirectedList.h:349)
==28883==    by 0x403F26: main (NinetyNine.cpp:52)
==28883==  Address 0x5a060f0 is 32 bytes inside a block of size 64 free'd
==28883==    at 0x4C2A360: operator delete(void*) (vg_replace_malloc.c:507)
==28883==    by 0x405DD6: CircularDoubleDirectedList<Player>::remove(Player&) (CircularDoubleDirectedList.h:323)
==28883==    by 0x403F26: main (NinetyNine.cpp:52)
==28883==
==28883== Invalid read of size 1
==28883==    at 0x4C2ED29: __memcmp_sse4_1 (vg_replace_strmem.c:972)
==28883==    by 0x403BF1: std::char_traits<char>::compare(char const*, char const*, unsigned long) (char_traits.h:259)
==28883==    by 0x403CE5: __gnu_cxx::__enable_if<std::__is_char<char>::__value, bool>::__type std::operator==<char>(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) (in /root/.CLion12/system/cmake/generated/7eeba64d/7eeba64d/Debug0/DV1490_lab2_99)
==28883==    by 0x403B44: Player::operator==(Player const&) const (Player.cpp:92)
==28883==    by 0x4068FD: CircularDoubleDirectedList<Player>::operator==(Player const&) (CircularDoubleDirectedList.h:467)
==28883==    by 0x405E83: CircularDoubleDirectedList<Player>::remove(Player&) (CircularDoubleDirectedList.h:349)
==28883==    by 0x403F26: main (NinetyNine.cpp:52)
==28883==  Address 0x5a06018 is 24 bytes inside a block of size 26 free'd
==28883==    at 0x4C2A360: operator delete(void*) (vg_replace_malloc.c:507)
==28883==    by 0x403866: Player::~Player() (Player.cpp:34)
==28883==    by 0x4068D1: CircularDoubleDirectedList<Player>::Node::~Node() (CircularDoubleDirectedList.h:26)
==28883==    by 0x405DCE: CircularDoubleDirectedList<Player>::remove(Player&) (CircularDoubleDirectedList.h:323)
==28883==    by 0x403F26: main (NinetyNine.cpp:52)
==28883==
The number of players are 2
Sum of pile: 0
Player: q
At hand:
Card 1: Klöver 10
Card 2: Hjärter Kung
Card 3: Klöver Ess

enter 1 or 2 or 3 (or 9 for selfdestruct)

 */