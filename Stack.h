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
    Node *top;
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
    ; //meh!
}*/
template <class T>
//DBG: works
IStack<T>::~IStack() { }
template <class T>
//DBG: works
Stack<T>::Stack() : nrOfElements(0), top(nullptr)
{}

template <class T>
//DBG: ready4test
Stack<T>::~Stack()
{
    if( this->nrOfElements > 0)
    {
        Node *rm;
        while (this->top->next != nullptr)
        {
            rm = this->top;
            this->top = this->top->next;
            delete rm;
        }
        delete this->top;
        rm = nullptr;
    }
    this->top= nullptr;

}
template <class T>
//DBG: ready4test
void Stack<T>::push(const T &element)
{
    Node* ptr;
    //Node cc(element);
    if( this->nrOfElements < 1)
    {
        this->top = new Node(element);
        this->nrOfElements++;
    }
    else
    {
        ptr = new Node(element);
        ptr->next = this->top;
        this->top = ptr;
        this->nrOfElements++;
    }

}
template <class T>
//DBG: ready4test
T Stack<T>::pop() throw(string)
{
    T result = nullptr;
    Node*rm, *ptr;
    if(this->nrOfElements < 1)
    {
        throw string("Exception: empty queue");
    }
    result = this->top->data;
    rm = this->top;
    this->top = this->top->next;

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


