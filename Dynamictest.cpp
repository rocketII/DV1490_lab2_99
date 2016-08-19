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
    int a=2, b=9, c=3, d=8, e=22;
    CircularDoubleDirectedList<int> test;
    test.add(a);
    test.add(b);
    test.remove(a);
    try{ test.remove(d);} catch (string& s) { cout <<endl<< s<<endl; }
    /*test.add(c);
    test.add(d);
    test.add(e);
    test.changeDirection();
    test.move();
    test.move();
    test.move();
    test.move();test.move();*/
    cout;
    return 0;
}
