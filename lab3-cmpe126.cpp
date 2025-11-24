//============================================================================
// Name        : lab3-cmpe126.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include "arrayList.h"
using namespace std;

int main() {


	arrayList<int> n(5);
	cout << "Is it Empty: " << n.isEmpty() << endl; //Test if array is empty

	n.insertEnd(69);	//inserting 2 values
	n.insertEnd(21);
	n.print();			//printing array

	cout << "Is it Full: " << n.isFull() << endl;	// test if full
	cout << "Current Array Size: " << n.listSize() << endl;	//Array Size

	n.insertAt(1, 1); //Inserting value at position
	n.print();

	cout << "Is 1 equal to position 1: " << n.isItemAtEqual(1, 1) << endl;	//Testing if Item is equal at position

	cout << "Retrieve Position 2: " << n.retrieveAt(2) << endl;	//Returning value at position

	cout << "Max List Size: " << n.maxListSize() << endl;	//Displaying the Max List Size for array

	n.insertEnd(76);
	n.insertEnd(96);
	n.print();

	cout << "Is it Full: " << n.isFull() << endl;

	n.removeAt(3);	//Removing value at a position
	cout << "Removing 76..." << endl;
	n.print();

	n.insertAt(99, 10); //Testing Error Sequence
	n.removeAt(7);

	n.retrieveAt(200); // Test retrieve error
	return 0;
}
