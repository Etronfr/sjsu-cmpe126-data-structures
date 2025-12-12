//============================================================================
// Name        : lab9-cmpe126.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "hashtable.h"
#include "hashtablechaining.h"
#include "hashtablequad.h"
#include "arrayList.h"
#include "linkedListSearch.h"
#include "sortedarrayList.h"
using namespace std;

int main() {
arrayList<int> theList(10);
linkedListSearch<int> theLinkedListSearch;
sortedarrayList<int> sortedList(10);
HashTable HashTableLin(10);
HashTableChaining HashTableChain;	//Alr set with 10 buckets
HashTableQuad HashTableQ(10);

int values[] = {3, 2, 9, 4, 0, 5, 7, 5, 11, 15};
int n = 10;
	//Data for arrayList
for (int i = 0; i < n; i++) {
	theList.insert(values[i]);
}
	//Data for linkedList
for (int i = 0; i < n; i++) {
	theLinkedListSearch.insert(values[i]);
}
for (int i = 0; i < n; i++) {
	sortedList.insert(values[i]);
}
	unsigned int choice = 0;
	do {
	int key;
	int option = -1;
	cout << "Choose your search type:" << endl;
	cout << "1. Arrays: Sequential Search without recursion" << endl;
	cout << "2. Arrays: Sequential Search with recursion" << endl;
	cout << "3. Ordered Arrays: Binary Search without recursion" << endl;
	cout << "4. Ordered Arrays: Binary Search with recursion" << endl;
	cout << "5. Linked List: Search without recursion" << endl;
	cout << "6. Linked List: Search with recursion" << endl;
	cout << "7. Arrays: Hashing with linear probing" << endl;
	cout << "8. Arrays: Hashing with chaining" << endl;
	cout << "9. Arrays: Hashing with quadratic probing" << endl;
	cout << "Enter 0 to exit" << endl;
	cout << "Your choice: ";
	cin >> choice;
	cout << endl;
	switch (choice) {
	case 0: {
		cout << "Have a Good Day.";
		return 0;
	}

	case 1: {
		int x;
		cout << "Please Input an integer to search for: ";
		cin >> x;
		int pos = theList.seqSearchIter(x);
		cout << (pos != -1 ? ("Your integer was found at index: " + to_string(pos)) : "Not Found.") << "\n" << endl;	//to_string bc needs to produce string
		break;
	}
	case 2: {
		int x;
		cout << "Please Input an integer to search for: ";
		cin >> x;
		int pos = theList.seqSearchRec(x, 0);
		cout << (pos != -1 ? ("Your integer was found at index: " + to_string(pos)) : "Not Found.") << "\n" << endl;
		break;
	}
	case 3: {
		int x;
		cout << "Please Input an integer to search for: ";
		cin >> x;
		int pos = sortedList.binarySearchIter(x);
		cout << (pos != -1 ? ("Your integer was found at index: " + to_string(pos)) : "Not Found.") << "\n" << endl;
		break;
	}
	case 4: {
		int x;
		cout << "Please Input an integer to search for: ";
		cin >> x;
		int pos = sortedList.binarySearchRec(x, 0, sortedList.listSize() - 1);
		cout << (pos != -1 ? ("Your integer was found at index: " + to_string(pos)) : "Not Found.") << "\n" << endl;
		break;
	}
	case 5: {
		int x;
		cout << "Please Input an integer to search for: ";
		cin >> x;
		int pos = theLinkedListSearch.seqSearchIter(x);
		cout << (pos != -1 ? ("Your integer was found at index: " + to_string(pos)) : "Not Found.") << "\n" << endl;
		break;
	}
	case 6: {
		int x;
		cout << "Please Input an integer to search for: ";
		cin >> x;
		int pos = theLinkedListSearch.seqSearchRec(x);
		cout << (pos != -1 ? ("Your integer was found at index: " + to_string(pos)) : "Not Found.") << "\n" << endl;
		break;
	}
	case 7: {	//HashTable Linear Probing
		while (option != 0) {
		cout << "Choose an option:" << endl;
		cout << "1. Insert: " << endl;
		cout << "2. Search: " << endl;
		cout << "3. Remove:" << endl;
		cout << "Enter 0 to go back" << endl;
		cout << "Your Choice: ";
		cin >> option;
		cout << endl;
		if (option != 0) {	//If wanting to exit do not ask for key
		cout << "Enter Key for function: ";
		cin >> key;
		cout << endl;
		}
		switch (option) {
		case 1: {
			HashTableLin.insert(key);
			HashTableLin.print();
			break;
		}
		case 2: {
			HashTableLin.search(key);
			HashTableLin.print();
			break;
		}
		case 3: {
			HashTableLin.remove(key);
			HashTableLin.print();
			break;
		}
		}
		}
		break;
	}

	case 8: {	//HashTable Chaining
		while (option != 0) {
		cout << "Choose an option:" << endl;
		cout << "1. Insert: " << endl;
		cout << "2. Search: " << endl;
		cout << "3. Remove:" << endl;
		cout << "Enter 0 to go back" << endl;
		cout << "Your Choice: ";
		cin >> option;
		cout << endl;
		if (option != 0) {	//If wanting to exit do not ask for key
		cout << "Enter Key for function: ";
		cin >> key;
		cout << endl;
		}
		switch (option) {
		case 1: {
			HashTableChain.insert(key);
			HashTableChain.print();
			break;
		}
		case 2: {
			HashTableChain.search(key);
			HashTableChain.print();
			break;
		}
		case 3: {
			HashTableChain.remove(key);
			HashTableChain.print();
			break;
		}
		}
	}
	break;
	}
	case 9: {	//HashTable Quadratic Probing
		while (option != 0) {
		cout << "Choose an option:" << endl;
		cout << "1. Insert: " << endl;
		cout << "2. Search: " << endl;
		cout << "3. Remove:" << endl;
		cout << "Enter 0 to go back" << endl;
		cout << "Your Choice: ";
		cin >> option;
		cout << endl;
		if (option != 0) {	//If wanting to exit do not ask for key
		cout << "Enter Key for function: ";
		cin >> key;
		cout << endl;
		}
		switch (option) {
		case 1: {
			HashTableQ.insert(key);
			HashTableQ.print();
			break;
		}
		case 2: {
			HashTableQ.search(key);
			HashTableQ.print();
			break;
		}
		case 3: {
			HashTableQ.remove(key);
			HashTableQ.print();
			break;
			}
		}
		}
	break;
	}
	}

	}
	while(choice!=0);

	return 0;
}

