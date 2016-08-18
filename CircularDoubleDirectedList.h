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
T hold_DBG;
public:
    //Inherited
    CircularDoubleDirectedList() : hold_DBG(2) {}
    void add(T& item);
    bool remove(T& item); // requires == operator of item
    int size() const;
    T& currentItem();
    void changeDirection();
    void move();
};
template <class T>
void CircularDoubleDirectedList<T>::add(T &item)
{

}
template <class T>
bool CircularDoubleDirectedList<T>::remove(T &item)
{
    return false;
}

template <class T>
int CircularDoubleDirectedList<T>::size() const
{
    return 0;
}

template <class T>
T &CircularDoubleDirectedList<T>::currentItem()
{
    return this->hold_DBG;
}
template <class T>
void CircularDoubleDirectedList<T>::changeDirection()
{

}
template <class T>
void CircularDoubleDirectedList<T>::move()
{

}

#endif //DV1490_LAB2_99_CIRCULARDOUBLEDIRECTEDLIST_H
