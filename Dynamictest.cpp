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
    int a=0, b=-9;
    CircularDoubleDirectedList<int> test;
    for (int i = 0; i < 2; i++)
    {
        a = i;
        test.add(a);
    }

    CircularDoubleDirectedList<int> test2 = test;
    cout << "\n a\n";
    for (int i = 0; i < 2; i++)
    {
        a = i;
        test.remove(a);
    }
    test2.add(b);
    //try{ test.remove(d);} catch (string& s) { cout <<endl<< s<<endl; }
    test.add(b);
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
