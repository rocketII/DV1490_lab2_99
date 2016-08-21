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
        Node* prev;
        Node(T data): next(nullptr), data(data) { }
        ~Node(){};
    };
    int nrOfElements;

    Node* ptr, *current;
public:
    Stack();
    ~Stack();
    virtual void push(const T& element);
    virtual T pop();
    virtual T peek() const;
    virtual bool isEmpty() const;
};
template <class T>
Stack::Stack() : nrOfElements(0), ptr(nullptr)
{}
template <class T>
Stack::~Stack()
{

}
template <class T>
void Stack::push(const T &element)
{

}
template <class T>
T Stack::pop() throw(string)
{
    T result;
    Node* rm;
    if(this->nrOfElements < 1)
    {
        throw string("Exception: empty queue");
    }
    result = this->current->data;
    rm = this->current;
    this->current = this->current->prev;
    delete rm;
    return result;
}
template <class T>
T Stack::peek() const throw(string)
{
    if(this->nrOfElements < 1)
    {
        throw string("Exception: empty queue");
    }
    return this->current->data;
}

bool Stack::isEmpty() const
{

    return false;
}

#endif //DV1490_LAB2_99_STACK_H_H
