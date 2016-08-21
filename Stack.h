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
    virtual void push(const T& element);
    virtual T pop()throw(string);
    virtual T peek() const throw(string);
    virtual bool isEmpty() const;
};
template <class T>
IStack<T>::~IStack() { }
template <class T>
Stack<T>::Stack() : nrOfElements(0), ptr(nullptr), top(nullptr)
{}

template <class T>
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
void Stack<T>::push(const T &element)
{
    if( this->nrOfElements < 1)
    {
        this->ptr = new Node(element);
        this->top = this->ptr;
    }
    else
    {
        this->top->next = new Node(element);
        this->top = this->top->next;
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
    return result;
}
template <class T>
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
