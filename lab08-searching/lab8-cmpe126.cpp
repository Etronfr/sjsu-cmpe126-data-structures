//============================================================================
// Name        : VS-CMPE126-Lab-3.cpp
// Author      : Ethan Valdueza
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "arrayList.h"
#include "linkedList.h"
#include "sortedarrayList.h"
#include <iostream>
using namespace std;

int main() {
		arrayList<int> theList(100);
		linkedList<int> theLinkedList;
		sortedarrayList<int> sortedList(100);

		//Data for arrayList
		theList.insert(0);
		theList.insert(4);
		theList.insert(7);
		theList.insert(9);
		theList.insert(8);
		theList.insert(3);
		theList.insert(1);
		theList.insert(2);
		theList.insert(6);
		theList.insert(5);

		//Data for linkedList
		theLinkedList.insert(0);
		theLinkedList.insert(4);
		theLinkedList.insert(7);
		theLinkedList.insert(9);
		theLinkedList.insert(8);
		theLinkedList.insert(3);
		theLinkedList.insert(1);
		theLinkedList.insert(2);
		theLinkedList.insert(6);
		theLinkedList.insert(5);

		//Data for sortedarrayList
		sortedList.insert(0);
		sortedList.insert(4);
		sortedList.insert(7);
		sortedList.insert(9);
		sortedList.insert(8);
		sortedList.insert(3);
		sortedList.insert(1);
		sortedList.insert(2);
		sortedList.insert(6);
		sortedList.insert(5);
	unsigned int choice = 0;
	do {
	cout << "Choose your search type:" << endl;
	cout << "1. Arrays: Sequential Search without recursion" << endl;
	cout << "2. Arrays: Sequential Search with recursion" << endl;
	cout << "3. Ordered Arrays: Binary Search without recursion" << endl;
	cout << "4. Ordered Arrays: Binary Search with recursion" << endl;
	cout << "5. Linked List: Search without recursion" << endl;
	cout << "6. Linked List: Search with recursion" << endl;
	cout << "Enter 0 to exit" << endl;
	cout << "Your choice: ";
	cin >> choice;

	switch (choice) {
	case 0: {
		cout << "Have a Good Day.";
		return 0;
	}

	case 1: {
		int x;
		cout << "Please Input an integer to search for: ";
		cin >> x;
		cout << "Your integer has been found at index: " << theList.seqSearchIter(x) << endl;
		break;
	}
	case 2: {
		int x;
		cout << "Please Input an integer to search for: ";
		cin >> x;
		cout << "Your integer has been found at index: " << theList.seqSearchRec(x, 0) << endl;
		break;
	}
	case 3: {
		int x;
		cout << "Please Input an integer to search for: ";
		cin >> x;
		cout << "Your integer has been found at index: " << sortedList.binarySearchIter(x) << endl;
		break;
	}
	case 4: {
		int x;
		cout << "Please Input an integer to search for: ";
		cin >> x;
		cout << "Your integer has been found at index: " << sortedList.binarySearchRec(x, 0, sortedList.listSize() - 1) << endl;
		break;
	}
	case 5: {
		int x;
		cout << "Please Input an integer to search for: ";
		cin >> x;
		cout << "Your integer has been " << (theLinkedList.seqSearchIter(x) ? "Found" : "Not Found In List") << endl;
		break;
	}
	case 6: {
		int x;
		cout << "Please Input an integer to search for: ";
		cin >> x;
		cout << "Your integer has been " << (theLinkedList.seqSearchRec(x) ? "Found" : "Not Found In List") << endl;
		break;
	}
	}
	cout<<"\nSpecify the element to be searched for: ";

	}
	while(choice!=0);

	return 0;
	}





