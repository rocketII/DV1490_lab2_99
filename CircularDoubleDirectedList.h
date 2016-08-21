//
// Created by root on 2016-08-18.
//
/*
 * Bug#     description                                                                                         solved?
 * 0x00     deepcopy dosen't make identical chain(items>2), one position wrong. missing on element.                 0
 */
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
    //this->nrOfItems = origin.nrOfItems;
    this->nrOfItems=0;
    this->currentDirection = origin.currentDirection;
    //Deep copy and stuff
    Node* stop = origin.current;
    Node* tmp;
    if (origin.nrOfItems > 2)
    {
        Node* start;
        tmp = origin.current;
        this->current = new Node(tmp->data);
        this->nrOfItems++;
        start = this->current;
        tmp = tmp->next;
        this->current->next = new Node(tmp->data);
        this->nrOfItems++;
        tmp = tmp->next;
        this->current->next->prev = this->current;
        this->current = this->current->next;
        do
        {
            this->current->next = new Node(tmp->data);
            this->nrOfItems++;
            tmp = tmp->next;
            this->current->next->prev = this->current;
            this->current = this->current->next;


        }while (tmp->next != stop);
        this->current->next = start;
        this->current->next->prev = this->current;
    }
    else if ( origin.nrOfItems == 2)
    {
        tmp = origin.current;
        this->current = new Node(tmp->data);
        this->nrOfItems++;
        tmp = tmp->next;
        this->current->next = new Node(tmp->data);
        this->nrOfItems++;
        this->current->next->prev = this->current;
        this->current->next->next = this->current;
        this->current->prev = this->current->next;
        //this->current = this->current->next; obsolete
    }
    else if ( origin.nrOfItems == 1)
    {
        this->current = new Node(origin.current->data);
        this->nrOfItems++;
        this->current->next = this->current;
        this->current->prev = this->current;
    }
    else
        this->current = nullptr;
}


template <class T>
//DBG: works
CircularDoubleDirectedList<T>::~CircularDoubleDirectedList()
{
    //kolla om tom.
    //om innehåll förstör alla noder som allokerats.
    bool flag = false;
    if(this->nrOfItems < 1)
        ;
    else
    {
        if(this->nrOfItems > 2) //works
        {
            int upperlimit = this->nrOfItems;
            for (int u = 0; u < upperlimit ; u++)
            {
                if(this->nrOfItems > 2)
                {
                    if (!flag)
                    {
                        this->current->prev->next = nullptr;
                        flag = true;
                    }
                    this->current = this->current->next;
                    delete this->current->prev;
                    this->nrOfItems--;
                }
                else if(this->nrOfItems == 2)
                {
                    this->current = this->current->next;
                    delete this->current->prev;
                    delete this->current;
                    this->nrOfItems-=2;
                }

            }
        }
        else if(this->nrOfItems == 2)//works fine
        {
            delete this->current->next;
            this->nrOfItems--;
            delete this->current;
            this->nrOfItems--;
            this->current = nullptr;
        }
        else if(this->nrOfItems == 1)//works fine
        {
             delete this->current;
             this->nrOfItems--;
             this->current = nullptr;
        }
    }
}


template <class T>
//DBG: bug 0x00
CircularDoubleDirectedList<T> &CircularDoubleDirectedList<T>::operator=(const CircularDoubleDirectedList<T> &origin)
{
    //dummy code
    if(this != &origin)
    {
        this->nrOfItems = origin.nrOfItems;
        this->currentDirection = origin.currentDirection;
        //Deep copy and stuff
        Node* stop = origin.current;
        Node* tmp;
        if (origin.nrOfItems > 2)
        {
            Node* start;
            tmp = origin.current;
            this->current = new Node(tmp->data);
            start = this->current;
            tmp = tmp->next;
            this->current->next = new Node(tmp->data);
            tmp = tmp->next;
            this->current->next->prev = this->current;
            this->current = this->current->next;
            do
            {
                this->current->next = new Node(tmp->data);
                tmp = tmp->next;
                this->current->next->prev = this->current;
                this->current = this->current->next;


            }while (tmp->next != stop);
            this->current->next = start;
            this->current->next->prev = this->current;
        }
        else if ( this->nrOfItems == 2)
        {
            tmp = origin.current;
            this->current = new Node(tmp->data);
            tmp = tmp->next;
            this->current->next = new Node(tmp->data);
            this->current->next->prev = this->current;
            this->current->next->next = this->current;
            this->current->prev = this->current->next;
            this->current = this->current->next;
        }
        else if ( this->nrOfItems == 1)
        {
            this->current = new Node(origin.current->data);
            this->current->next = this->current;
            this->current->prev = this->current;
        }
        else
            this->current = nullptr;
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
//DBG: works
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
//DBG: works
bool CircularDoubleDirectedList<T>::remove(T &item) throw(std::string)
{
    bool flag = false;
    Node* exterminate = nullptr;
    if(this->nrOfItems < 1)
    {
        throw std::string("Exception: call of remove on empty list");
    }
    else
    {
        //search linear time.
        //Better: could sort att then use binary search.
        for (int i = 0; i < this->size() ; ++i)
        {
            if(this->size() > 2)
            {
                if( this->current->data == item)
                {
                    exterminate = this->current;
                    this->current->next->prev = this->current->prev;
                    this->current->prev->next = this->current->next;
                    this->current = this->current->prev ;
                    delete exterminate;
                    this->nrOfItems--;
                    flag = true;
                }
                else
                {
                    this->move();
                }
            }
            else if(this->size() == 2)
            {
                if( this->current->data == item)
                {
                    exterminate = this->current;
                    this->current = this->current->next;
                    this->current->next->prev = this->current->next;
                    this->current->next->next = this->current->next;
                    delete exterminate;
                    this->current->next = this->current;
                    this->current->prev = this->current;
                    this->nrOfItems--;
                    flag = true;
                }
                else
                    this->move();
            }
            else if(this->size() == 1)
            {
                if( this->current->data == item)
                {
                    exterminate = this->current;
                    this->current->next = this->current;
                    this->current->prev = this->current;
                    delete exterminate;
                    this->current = nullptr;
                    this->nrOfItems--;
                    flag = true;
                }
            }
        }
    }
    return flag;
}


template <class T>
// o Returnerar antalet element som finns i listan.
//DBG: works
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
//DBG: works
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
//DBG: works
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

//DBG: works
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
