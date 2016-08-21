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
    for (int i = 0; i < 3; i++)
    {
        a = i;
        test.add(a);
    }
    cout <<"test size:" <<test.size();
    //CircularDoubleDirectedList<int> test2 = test;
    cout << "\n a\n";
   /* for (int i = 0; i < 1; i++)
    {
        a = i;
        test.remove(a);
    }*/
    //test2.add(b);
    //cout << "test2 size:" <<test2.size();
    //try{ test.remove(d);} catch (string& s) { cout <<endl<< s<<endl; }
    //test.add(b);
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
// 1 items  ==  ==11408== All heap blocks were freed -- no leaks are possible
//   copying works
// 2 items  ==  ==11408== All heap blocks were freed -- no leaks are possible
//   copying works
// >2 items  ==  leaks
//   copying dosen't works

