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
#include "Stack.h"
using namespace std;
void ListDemo(void);
void stackDemo(void);
int main()
{
    stackDemo();
    //ListDemo();
    cout;
    return 0;
}
void stackDemo(void)
{
    stack<int> test77;
}
void ListDemo()
{
    int limit = 5;
    int a=0, b=-9;
    CircularDoubleDirectedList<int> test, test3;
    for (int i = 0; i < limit; i++)
    {
        a = i;
        test.add(a);
    }
    cout <<"test size:" <<test.size();
    CircularDoubleDirectedList<int> test2 = test;
    test3 = test;
    cout << "\n a\n";
    for (int i = 0; i < limit; i++)
    {
        a = i;
        test.remove(a);
    }
    //test2.add(b);
    //cout << "test2 size:" <<test2.size();
    //try{ test.remove(d);} catch (string& s) { cout <<endl<< s<<endl; }
    //test.add(b);
}
// 1 items  ==  ==11408== All heap blocks were freed -- no leaks are possible
//   copying works
// 2 items  ==  ==11408== All heap blocks were freed -- no leaks are possible
//   copying works
// >2 items  ==  leaks
//   copying dosen't works

