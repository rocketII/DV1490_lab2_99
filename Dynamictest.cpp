//
// Created by root on 2016-08-18.
// Test anything goes
//

#include <string>
#include "CircularDoubleDirectedList.h"
#include "Stack.h"
#include "Card.h"
#include <iostream>
using namespace std;
void ListDemo(void);
void stackDemo();
int main()
{
    Card* ptr[8];
    Card* hold;
    Stack<Card*> test77;
    Card a("Hjärter",1,"Ess");
    test77.push(&a);
    Card b("Spader",1,"Ess");
    test77.push(&b);
    Card c("Ruter",1,"Ess");
    test77.push(&c);
    Card d("Klöver",1,"Ess");
    test77.push(&d);
    Card aa("Hjärter",2,"2");
    test77.push(&aa);
    Card bb("Spader",2,"2");
    test77.push(&bb);
    Card cc("Ruter",2,"2");
    test77.push(&cc);
    Card dd("Klöver",2,"2");
    test77.push(&dd);
    cout << "\n-------------------"<<endl;
    ptr[0] = test77.peek();
    test77.pop();
    ptr[1] = test77.peek();
    test77.pop();
    ptr[2] = test77.peek();
    test77.pop();
    ptr[3] = test77.peek();
    test77.pop();
    ptr[4] = test77.peek();
    test77.pop();
    ptr[5] = test77.peek();
    test77.pop();
    ptr[6] = test77.peek();
    test77.pop();
    ptr[7] = test77.peek();
    test77.pop();
    cout << ptr[0]->toString()<<" value: "<< ptr[0]->getValue()<< endl;
    cout << ptr[1]->toString()<<" value: "<< ptr[1]->getValue()<< endl;
    cout << ptr[2]->toString()<<" value: "<< ptr[2]->getValue()<< endl;
    cout << ptr[3]->toString()<<" value: "<< ptr[3]->getValue()<< endl;
    cout << ptr[4]->toString()<<" value: "<< ptr[4]->getValue()<< endl;
    cout << ptr[5]->toString()<<" value: "<< ptr[5]->getValue()<< endl;
    cout << ptr[6]->toString()<<" value: "<< ptr[6]->getValue()<< endl;
    cout << ptr[7]->toString()<<" value: "<< ptr[7]->getValue()<< endl;
    test77.push(ptr[7]);
    test77.push(ptr[6]);
    test77.push(ptr[5]);
    test77.push(ptr[4]);
    test77.push(ptr[3]);
    test77.push(ptr[2]);
    test77.push(ptr[1]);
    test77.push(ptr[0]);
    //ListDemo();

    return 0;
}
void stackDemo()
{



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

