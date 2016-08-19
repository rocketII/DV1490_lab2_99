//
// Created by root on 2016-08-18.
//
#ifndef DV1490_LAB2_99_CIRCULARDOUBLEDIRECTEDLIST_H
#define DV1490_LAB2_99_CIRCULARDOUBLEDIRECTEDLIST_H

#include <string>
#include <stddef.h>
#include "ICircularDoubleDirectedList.h"

template <class T>
class CircularDoubleDirectedList : ICircularDoubleDirectedList<T>
{
private:
    class Node
    {
    public:
        T data;
        Node* next, *prev;
        Node(T data): prev(nullptr), next(nullptr), data(data) { }
        ~Node(){};
    };

    int nrOfItems;
    direction currentDirection;
    Node* current;
public:
    //necesary
    CircularDoubleDirectedList() :  currentDirection(NEXT), nrOfItems(0), current(nullptr) {} //inline but so small.
    CircularDoubleDirectedList(const CircularDoubleDirectedList& origin);
    virtual ~CircularDoubleDirectedList();
    //other
    CircularDoubleDirectedList& operator=(const CircularDoubleDirectedList& origin);
    //Inherited
    virtual void add(T& item);
    virtual bool remove(T& item) throw(std::string); // requires == operator of item
    virtual int size() const;
    virtual T& currentItem() throw(std::string);
    virtual void changeDirection();
    virtual void move()throw(std::string);
};


template <class T>
CircularDoubleDirectedList<T>::CircularDoubleDirectedList(const CircularDoubleDirectedList &origin)
{
    this->nrOfItems = 0;
    this->current = nullptr;
    if (origin.nrOfItems > 0)
    {
        /*   //dummy code
        this->nrOfItems = origin.nrOfItems;
        this->first = new Node(origin.first->data);
        //alternative 2
        //T theData = orgin.first->data;
        //Node* aNode=new Node(theData);
        //this->first=aNode;
        Node* walker = origin.first;
        Node* endNodePtr = this->first;
        for (int i = 0; i < this->nrOfElements-1 ; ++i)
        {
            walker = walker->next;
            endNodePtr->next= new Node(walker->data);
            endNodePtr = endNodePtr->next;
        }*/
    }
}


template <class T>
CircularDoubleDirectedList<T>::~CircularDoubleDirectedList()
{
    //kolla om tom.
    //om innehåll förstör alla noder som allokerats.
    if(this->nrOfItems < 0)
        ;
    else
    {
        for (int i = 0; i < this->nrOfItems ; ++i)
        {
            ;
        }
    }
}


template <class T>
CircularDoubleDirectedList<T> &CircularDoubleDirectedList<T>::operator=(const CircularDoubleDirectedList<T> &origin)
{
    //dummy code
    if(this != &origin)
    {
        T test;
    }
    return *this;
}

///////////////////////////////////////////////

template <class T>
/*
 *o Om listan är tom skapas en nod för item vilken blir den enda noden i listan. Den
    nya noden är därefter aktuell nod.
  o En ny nod skapas för item vilken placeras efter aktuell nod, d.v.s blir efterföljare
    till aktuell nod. Den nya noden ska därefter bli aktuell nod.
 */ //description
void CircularDoubleDirectedList<T>::add(T &item)
{
    if(this->nrOfItems == 0)
    {
        this->current = new Node(item);
        this->current->prev =this->current;
        this->current->next = this->current;
        this->nrOfItems++;
    }
    else
    {
        if(this->nrOfItems == 1)
        {
            // think pearl necklace :)
            this->current->next = new Node(item);
            this->current->next->prev = this->current;
            this->current->prev = this->current->next;
            this->current->next->next = this->current;
            this->current = this->current->next;
            this->nrOfItems++;
        }
        else
        {
            Node* tmp = this->current->prev;
            this->current->prev = new Node(item);
            this->current->prev->prev= tmp;
            this->current->prev->prev->next = this->current->prev;
            this->current->prev->next = this->current;
            this->current = this->current->prev;
            this->nrOfItems++;
        }
    }
}


template <class T>
/*
 *o Om listan är tom kastas strängen ”Exception: call of remove on empty list” som
    undantag.
  o Den nod som innehåller item tas bort. Om den nod som tas bort är den nod som
    är aktuell (current pekar på denna) ska aktuell nod bli efterföljande nod.
 */ //description
bool CircularDoubleDirectedList<T>::remove(T &item) throw(std::string)
{
    Node* rememberCurrent = this->current;
    bool flag = false;
    Node* exterminate = nullptr;
    if(this->nrOfItems < 0)
    {
        throw std::string("Exception: call of remove on empty list");
    }
    else
    {
        //search down. linear time.
        ;
    }
    this->current = rememberCurrent;
    return flag;
}


template <class T>
// o Returnerar antalet element som finns i listan.
int CircularDoubleDirectedList<T>::size() const
{
    return this->nrOfItems;
}


template <class T>
/*
 * o Om listan är tom kastas strängen ” Exception: call of currentItem on empty list”
     som undantag.
   o Returnerar det element som är aktuellt (som finns i den nod som current pekar
     på).
 */ //description
T &CircularDoubleDirectedList<T>::currentItem() throw(std::string)
{
    if(this->nrOfItems == 0)
    {
        throw std::string("Exception: call of currentItem on empty list");
    }
    else
    {
        return this->current->data;
    }

}


template <class T>
// o Ändrar riktningen för listan
void CircularDoubleDirectedList<T>::changeDirection()
{
    if(this->currentDirection == NEXT)
        this->currentDirection = PREV;
    else
        this->currentDirection = NEXT;
}


template <class T>
/*
 * o Om listan är tom kastas strängen ” Exception: call of move on empty list” som
     undantag.
   o Ändrar current till ”nästa” nod enligt den riktning som ges av
     currentDirection.
 */  //description


void CircularDoubleDirectedList<T>::move() throw(std::string)
{
    if(this->nrOfItems == 0)
    {
        throw std::string("Exception: call of move on empty list");
    }
    else
    {
        if( this->currentDirection == NEXT)
        {
            if(this->current->next == nullptr )
                ;
            else
            {
                this->current = this->current->next;
            }
        }
        else if ( this->currentDirection == PREV)
        {
            if(this->current->prev == nullptr )
                ;
            else
            {
                this->current = this->current->prev;
            }
        }
    }
}


/////////////////////////////////////////////////////////////
#endif //DV1490_LAB2_99_CIRCULARDOUBLEDIRECTEDLIST_H
