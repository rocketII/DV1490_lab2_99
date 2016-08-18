//
// Created by root on 2016-08-18.
// Test anything goes
//
/*
 * Frågor:
 * add()
 * o En ny nod skapas för item vilken placeras efter aktuell nod, d.v.s blir efterföljare
     till aktuell nod. Den nya noden ska därefter bli aktuell nod.
            ? vad menas med efter aktuell nod ?
 */
#include <iostream>
#include "CircularDoubleDirectedList.h"
using namespace std;
int main()
{
    CircularDoubleDirectedList<int> test;
    try
    {test.move();}
    catch (std::string& tmp)
    {
        cout << tmp;
    }
    return 0;
}
