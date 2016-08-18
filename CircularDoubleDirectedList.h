//
// Created by root on 2016-08-18.
//

#ifndef DV1490_LAB2_99_CIRCULARDOUBLEDIRECTEDLIST_H
#define DV1490_LAB2_99_CIRCULARDOUBLEDIRECTEDLIST_H

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
        Node* next, prev;
        Node(T data): prev(nullptr), next(nullptr), data(data) { }
        ~Node(){};
    };
    T hold_DBG;
    int nrOfItems;
    direction currentDirection;
    Node* current;
public:
    //necesary
    CircularDoubleDirectedList() : hold_DBG(2), currentDirection(NEXT) {} //inline but so small.
    CircularDoubleDirectedList(const CircularDoubleDirectedList& origin);
    virtual ~CircularDoubleDirectedList();
    //other
    CircularDoubleDirectedList& operator=(const CircularDoubleDirectedList& origin);
    //Inherited
    virtual void add(T& item);
    virtual bool remove(T& item); // requires == operator of item
    virtual int size() const;
    virtual T& currentItem();
    virtual void changeDirection();
    virtual void move();
};

template <class T>
CircularDoubleDirectedList<T>::CircularDoubleDirectedList(const CircularDoubleDirectedList &origin)
{
    this->nrOfItems = 0;
    this->current = nullptr;
    if (origin.nrOfItems > 0)
    {
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
        }
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
 */
void CircularDoubleDirectedList<T>::add(T &item)
{
    if(this->nrOfItems == 0) {
        this->current = new Node(item);
        this->nrOfItems++;
    }
    else
    {
        this->current->next = new Node(item);
        this->current->next->prev = this->current;
        this->current = this->current->next;
        this->nrOfItems++;
    }
}
template <class T>
/*
 *o Om listan är tom kastas strängen ”Exception: call of remove on empty list” som
    undantag.
  o Den nod som innehåller item tas bort. Om den nod som tas bort är den nod som
    är aktuell (current pekar på denna) ska aktuell nod bli efterföljande nod.
 */
bool CircularDoubleDirectedList<T>::remove(T &item)
{
    for (int i = 0; i < ; ++i) {

    }
    return false;
}

template <class T>
int CircularDoubleDirectedList<T>::size() const
{
    return this->nrOfItems;
}

template <class T>
T &CircularDoubleDirectedList<T>::currentItem()
{
    return *this->current;
}
template <class T>
void CircularDoubleDirectedList<T>::changeDirection()
{
    if(this->currentDirection == NEXT)
        this->currentDirection = PREV;
    else
        this->currentDirection = NEXT;
}
template <class T>
void CircularDoubleDirectedList<T>::move()
{

}
/////////////////////////////////////////////////////////////
#endif //DV1490_LAB2_99_CIRCULARDOUBLEDIRECTEDLIST_H
