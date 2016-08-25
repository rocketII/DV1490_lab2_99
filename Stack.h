//
// Created by root on 2016-08-21.
//

#ifndef DV1490_LAB2_99_STACK_H
#define DV1490_LAB2_99_STACK_H
#include "IStack.h"
#include <string>
using namespace std;
template <class T>
class Stack : public IStack<T>
{
private:
    class Node
    {
    public:
        T data;
        Node* next;
        Node(T data):  next(nullptr), data(data) { }
        ~Node(){};
    };
    int nrOfElements;

    Node* ptr, *top;
public:
    Stack();
    ~Stack();
    //Stack(const Stack& origin ); //never used in 99.cpp
    //Stack& operator=(const Stack& origin);  never used in 99.cpp
    virtual void push(const T& element);
    virtual T pop()throw(string);
    virtual T peek() const throw(string);
    virtual bool isEmpty() const;
};
//template <class T>
/*Stack<T>::Stack(const Stack& origin)
{
    this->nrOfElements = origin.nrOfElements;
    if(this->nrOfElements > 0)
    {
        this-> top = nullptr;
        Node* walker = origin.ptr;
        this->ptr = new Node(walker);
        this->top = this->ptr;
        if(walker->next != nullptr)
        {
            walker = walker->next;
        }

        while ( this->top->data != origin.top->data)
        {

            this->top->next= new Node(walker);
            this->top = this->top->next;
            if(walker->next != nullptr)
            {
                walker = walker->next;
            }
        }
    }
}*/
template <class T>
//DBG: works
IStack<T>::~IStack() { }
template <class T>
//DBG: works
Stack<T>::Stack() : nrOfElements(0), ptr(nullptr), top(nullptr)
{}

template <class T>
//DBG: works
Stack<T>::~Stack()
{
    if(this->nrOfElements > 0)
    {
        Node* del;
        while (this->top != this->ptr)
        {
            del = this->ptr ;
            this->ptr = this->ptr->next;
            delete del;
        }
        delete this->top;
        this->top= nullptr;
        this->ptr= nullptr;
    }
}
template <class T>
//DBG: works
void Stack<T>::push(const T &element)
{
    if( this->nrOfElements < 1)
    {
        this->top = new Node(element);
        this->ptr = this->top;
        this->nrOfElements++;
    }
    else
    {
        this->top->next = new Node(element);
        this->top = this->top->next;
        this->nrOfElements++;
    }


}
template <class T>
T Stack<T>::pop() throw(string)
{
    T result;
    Node* rm, *walker;
    if(this->nrOfElements < 1)
    {
        throw string("Exception: empty queue");
    }
    walker = this->ptr;
    for (int i = 0; i < (this->nrOfElements-2) ; ++i)
    {
        walker = walker->next;
    }
    result = this->top->data;
    rm = this->top;
    this->top = walker;
    delete rm;
    this->nrOfElements--;
    return result;
}
template <class T>
//DBG: works
T Stack<T>::peek() const throw(string)
{
    if(this->nrOfElements < 1)
    {
        throw string("Exception: empty queue");
    }
    else
        return this->top->data;
}
template <class T>
//DBG: works
bool Stack<T>::isEmpty() const
{
    if(this->nrOfElements < 1)
    {
        return true;
    }
    else
        return false;
}

#endif //DV1490_LAB2_99_STACK_H_H


