#include "CircularDoubleDirectedList.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
template <typename T>
void printList(CircularDoubleDirectedList<T>& list)
{
	for (int i=0; i<list.size(); i++)
	{
		cout<<list.currentItem()<<" ";
		list.move();
	}
}

template<typename T>
bool checkList(string expected, CircularDoubleDirectedList<T>& list)
{
	stringstream resultStream;
	string yourresult;
	for (int i = 0; i<list.size(); i++)
	{
		resultStream<<list.currentItem() << " ";
		list.move();
	}
	yourresult = resultStream.str();
	return expected == yourresult;

}

template <typename T>
void test(CircularDoubleDirectedList<T> list)
{
	int item = 80;
	list.add(item);
}


int main()
{
	int values[] = { 10, 20, 30, 40, 50, 60, 70 };
	int oddNrs[] = { 1, 3, 5, 7, 9 };
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CircularDoubleDirectedList<int> aList;
	CircularDoubleDirectedList<int> bList = aList; 
	string dummy;

	cout<<"******** Testing copy constructor on empty list ********"<<endl;

	if (checkList("", aList) && checkList("", bList))
		cout <<endl << "Check Ok " << endl;
	else
	{
		cout << endl << "Something is wrong" << endl;
		cout << endl << "Expected output: \nElements in aList: \nElements in bList" << endl << endl << "Your output: " << endl;

		cout << "Elements in aList ";
		printList(aList);

		cout << endl << "Elements in bList ";
		printList(bList);
		cout << endl;
		getline(cin, dummy);
	}
	cout<<endl<<"******** Testing copy constructor on list with content ********"<<endl;

	for (int i=0; i < 5; i++)
		aList.add(oddNrs[i]);

	aList.changeDirection();
	aList.move();
	CircularDoubleDirectedList<int> cList = aList;
	bool firstCheck = checkList("7 5 3 1 9 ", aList) && checkList("7 5 3 1 9 ", cList);

	if (!firstCheck)
	{
		cout << endl << "Something is wrong" << endl;
		cout << endl << "Expected output: \nElements in aList 7 5 3 1 9 \nElements in cList 7 5 3 1 9" << endl << endl << "Your output: " << endl;
		cout << "Elements in aList ";
		printList(aList);
		cout << endl << "Elements in cList ";
		printList(cList);
	}


	for (int i = 0; i < 3; i++)
		aList.remove(oddNrs[i]);
	
	aList.add(values[0]);
	for (int i = 2; i < 4; i++)
		cList.add(values[i]);

	if (checkList("10 7 9 ", aList) && checkList("40 30 7 5 3 1 9 ", cList))
		cout << endl << "Check Ok " << endl;
	else
	{
		cout << endl << "Something is wrong" << endl;
		cout << endl << endl << "Expected output: \nElements in aList 10 7 9\nElements in cList 40 30 7 5 3 1 9" << endl << endl << "Your output: " << endl;
		cout << "Elements in aList ";
		printList(aList);
		
		test(cList);

		cout << "\nElements in cList ";
		printList(cList);

		cout << endl;
		getline(cin, dummy);
	}

	CircularDoubleDirectedList<int> dList;
	CircularDoubleDirectedList<int> eList;

	
	cout<<endl<<"******** Testing assignment operator on empty list ********"<<endl;
	dList = eList;
	if (checkList("", dList) && checkList("", eList))
		cout << endl << "Check Ok " << endl;
	else
	{
		cout << endl << "Something is wrong" << endl;
		cout << endl << "Expected output: \nElements in dList \nElements in eList" << endl << endl << "Your output: " << endl;
		cout << "Elements in dList ";
		printList(dList);

		cout << endl << "Elements in eList ";
		printList(eList);
		cout << endl;
		getline(cin, dummy);
	}


	cout<<endl<<"**** Testing assignment operator on list with content assigned empty list****"<<endl;

	eList.add(values[0]);
	eList.add(values[1]);

	eList = dList;

	if (checkList("", eList) && checkList("", dList))
		cout << endl << "Check Ok " << endl;
	else
	{
		cout << endl << "Something is wrong" << endl;
		cout << endl << "Expected output: \nElements in dList\nElements in eList" << endl << endl << "Your output: " << endl;
		cout << "Elements in dList ";
		printList(dList);

		cout << endl << "Elements in eList ";
		printList(eList);
		cout << endl;
		getline(cin, dummy);
	}
	
	cout<<endl<<"***** Testing assignment operator on empty list assigned list with content *****"<<endl;
	eList.add(values[0]);
	eList.add(values[1]);
	eList.add(values[2]);

	dList = eList;

	firstCheck = checkList("30 10 20 ", eList) && checkList("30 10 20 ", dList);

	if (!firstCheck)
	{
		cout << endl << "Something is wrong" << endl;
		cout << "Expected output: \nElements in dList 30 10 20\nElements in eList 30 10 20" << endl << endl << "Your output: " << endl;
		cout << "Elements in dList ";
		printList(dList);

		cout << endl << "Elements in eList ";
		printList(eList);
		cout << endl;

		getline(cin, dummy);
	}

	dList.add(values[5]);
	eList.remove(values[1]);

	if (checkList("30 10 ", eList) && checkList("60 10 20 30 ", dList))
		cout << endl << "Check Ok " << endl;
	else
	{
		cout << endl << "Something is wrong" << endl;
		cout << endl << "Expected output: \nElements in dList 60 10 20 30 \nElements in eList 30 10" << endl << endl << "Your output: "<< endl;
		cout << "Elements in dList ";
		printList(dList);

		cout << endl << "Elements in eList ";
		printList(eList);
		cout << endl;
		getline(cin, dummy);
	}
	cout<<endl<<"***** Testing assignment operator on lists with content *****"<<endl<<endl;
	
	eList = dList;
	firstCheck = checkList("60 10 20 30 ", eList) && checkList("60 10 20 30 ", dList);
	if (!firstCheck)
	{
		cout << endl << "Something is wrong" << endl;
		cout << "Expected output: \nElements in dList 60 10 20 30\nElements in eList 60 10 20 30" << endl << endl << "Your output: " << endl;
		cout << "Elements in dList ";
		printList(dList);

		cout << endl << "Elements in eList ";
		printList(eList);
		cout << endl;

		getline(cin, dummy);
	}


	eList.remove(values[5]);
	eList.changeDirection();

	dList = eList;
	dList.changeDirection();
	dList.move();

	if (checkList("10 30 20 ", eList) && checkList("20 30 10 ", dList))
	{
		cout << endl << "Check Ok " << endl;
	}
	else
	{
		cout << endl << "Something is wrong" << endl;
		cout << "Expected output: \nElements in dList 20 30 10\nElements in eList 10 30 20" << endl << endl << "Your output: " << endl;
		cout << "Elements in dList ";
		printList(dList);

		cout << endl << "Elements in eList ";
		printList(eList);
		cout << endl;

		getline(cin, dummy);
	}
	cout<<endl<<"***** Testing assignment operator on a list assigned itself *****"<<endl;
	
	dList.changeDirection();
	dList = dList;
	if (checkList("20 10 30 ", dList))
	{
		cout << endl << "Check Ok " << endl;
	}
	else
	{
		cout << endl << "Something is wrong" << endl;
		cout << endl << "Expected output: \nElements in dList 20 10 30 " << endl << endl << "Your output: " << endl;
		cout << "Elements in dList ";
		printList(dList);
		cout << endl;

		getline(cin, dummy);
	}

	cout << endl << "***** Testing explicit call of destructor of list *****" << endl << endl; 
	

	ICircularDoubleDirectedList<int>* fList = new CircularDoubleDirectedList<int>();
	
	for (int i = 0; i < 5; i++)
	{
		fList->add(oddNrs[i]);
		fList->changeDirection();
		fList->move();
		fList->move();
	}
	fList->move();

	delete fList;
	cout<< "Check Ok" << endl << endl;
	getline(cin, dummy);
	return 0;
}