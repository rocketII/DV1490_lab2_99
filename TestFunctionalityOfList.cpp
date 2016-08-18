#include "CircularDoubleDirectedList.h"
#include <iostream>
#include <string>
#include <iomanip>
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
		resultStream << list.currentItem() << " ";
		list.move();
	}
	yourresult = resultStream.str();
	return expected == yourresult;

}


int main()
{
	int values[] = { 10, 20, 30, 40, 50, 60, 70 };
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	string dummy;
	int item= 100;
	CircularDoubleDirectedList<int> aList;

	cout << "********** Testing circularity on list with one element: **********" << endl;

	stringstream result;
	aList.add(item);
	result << aList.currentItem() << " ";
	aList.move();
	result << aList.currentItem() << " ";
	aList.changeDirection();
	for (int i = 0; i < 3; i++)
		result << aList.currentItem() << " ";
	aList.changeDirection();

	string yourResult = result.str();
	if (yourResult == "100 100 100 100 100 ")
		cout << endl << "Check Ok " << endl;
	else
	{
		cout << endl << "Something is wrong" << endl;
		cout << endl << "Expected output: 100 100 100 100 100 " << endl << "    Your output: ";

		aList.add(item);
		cout << aList.currentItem() << " ";
		aList.move();
		cout << aList.currentItem() << " ";
		aList.changeDirection();
		for (int i = 0; i < 3; i++)
			cout << aList.currentItem() << " ";
		aList.changeDirection();

		getline(cin, dummy);
	}
	cout <<endl << "********** Testing removing on list with one element: **********" << endl;
	aList.remove(item);
	if (checkList("", aList))
		cout << endl << "Check Ok " << endl;
	else
	{
		cout << endl << "Something is wrong" << endl;
		cout << endl << "Expected output:  " << endl << "    Your output: ";
		
		printList(aList);

		getline(cin, dummy);
	}

	cout << endl << "********** Testing removing on empty list: **********" << endl;

	try
	{

		aList.remove(item);
		printList(aList);
	}
	catch (char* e)
	{
		cout << endl << "Check Ok " << endl;
		cout << e << endl;
	}

	cout << endl << "********** Testing function currentItem on empty list: **********" << endl;

	//cout << endl << "Expected output: Exception: call of currentItem on empty list" << endl << "    Your output: ";

	try
	{
		aList.currentItem();
		printList(aList);
	}
	catch (char* e)
	{
		cout << endl << "Check Ok " << endl;
		cout << e << endl;
	}


	cout << endl << "********** Testing function move on empty list: **********" << endl;


	try
	{
		cout << endl << "Check Ok " << endl;
		aList.move();
		printList(aList);
	}
	catch (char* e)
	{
		cout << e << endl;
	}


	cout << endl << "********** Testing add on an empty list: **********" << endl;
	for (int i = 0; i < 7; i++)
	{
		aList.add(values[i]);
	}
	aList.move();

	if (checkList("10 20 30 40 50 60 70 ", aList))
	{
		cout << endl << "Check Ok " << endl;
	}
	else
	{
		cout << endl << "Something is wrong" << endl;

		cout << endl << "Expected output: 10 20 30 40 50 60 70" << endl << "    Your output: ";
		
		printList(aList);

		getline(cin, dummy);
	}
	cout<<endl<<endl<<"********** Testing remove function: **********"<<endl;
	for (int i = 0; i < 7; i += 2)
	{
		aList.remove(values[i]);
	}
	
	if (checkList("20 40 60 ", aList))
	{
		cout << endl << "Check Ok " << endl;
	}
	else
	{
		cout << endl << "Something is wrong" << endl;

		cout << endl << "Expected output: 20 40 60" << endl << "    Your output: ";
		printList(aList);

		getline(cin, dummy);
	}
	cout << endl << endl << "********** Testing move and changeDirection function: **********" << endl;

	aList.move();
	aList.move();
	bool firstCheck = checkList("60 20 40 ", aList);
	if (!firstCheck)
	{
		cout << endl << "Something is wrong" << endl;
		cout << endl << "Expected output:60 20 40 "<<endl;
		printList(aList);
	}
	aList.changeDirection();
	aList.move();
	aList.move();
	aList.changeDirection();

	if (checkList("20 40 60 ", aList))
	{
		cout << endl << "Check Ok " << endl;
	}
	else
	{
		cout << endl << "Something is wrong" << endl;
		cout << "Expected output: 20 40 60" << endl;
		printList(aList);

		cout << endl << endl;

		getline(cin, dummy);
	}

	cout << endl << endl << "********** Testing circularity: **********" << endl;

	

	stringstream circresult;
	for (int i = 0; i < 10; i++)
	{
		circresult << aList.currentItem() << " ";
		aList.move();
	}
	aList.changeDirection();
	circresult << "## ";
	for (int i = 0; i < 7; i++)
	{
		circresult << aList.currentItem() << " ";
		aList.move();
	}
	yourResult = circresult.str();

	if (yourResult == "20 40 60 20 40 60 20 40 60 20 ## 40 20 60 40 20 60 40 ")
		cout << endl << "Check Ok " << endl;
	else
	{
		cout << endl << "Something is wrong" << endl;
		cout << endl << "Expected output: 20 40 60 20 40 60 20 40 60 20 ## 40 20 60 40 20 60 40" << endl << "    Your output: ";
		for (int i = 0; i < 10; i++)
		{
			cout << aList.currentItem() << " ";
			aList.move();
		}
		aList.changeDirection();
		cout << "## ";
		for (int i = 0; i < 7; i++)
		{
			cout << aList.currentItem() << " ";
			aList.move();
		}
		getline(cin, dummy);
	}
	getline(cin, dummy);
	return 0;
}