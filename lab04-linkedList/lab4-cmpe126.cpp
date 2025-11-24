//============================================================================
// Name        : lab4-cmpe126.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "linkedList.h"
#include "complexNumber.h"
using namespace std;

int main() {

	linkedList<int> W; // linkedList object called W for dubs
	cout << "isEmpty(): " << W.isEmpty() << endl;	// isEmpty
	cout << "listSize(): " << W.listSize() << " and maxListSize(): " << W.maxListSize() <<  endl;	// listSize and maxListSize
	cout << "isFull(): " << W.isFull() << endl;	// isFull

	int v10 = 10, v20 = 20, v30 = 30, v40 = 40, v50 = 50;	//values to pass thru

	W.insertEnd(v10);
	W.insertEnd(v20);	// insertEnd47
	W.insertEnd(v30);
	cout << "W -> Insert End: 10, 20, 30 = "; W.print(); cout << endl;

	W.insertAt(1, v40);	// insertAt
	cout << "W -> Insert At (1, 40) = "; W.print(); cout << endl;

	cout << "is ItemAtEqual (2, 20): " << W.isItemAtEqual(2, v20) << endl;	// isItemAt pos 2 Equal to 20

	int one = W.retreiveAt(0);	// retreiveAt pos 0
	cout << "retreiveAt(0): " << one << endl;

	W.replaceAt(3, v50);	// replaceAt 3 with 50
	cout << "W -> ReplaceAt(3, 50) = "; W.print(); cout << endl;

	W.removeAt(1);	//removing data at node 1
	cout << "W -> removeAt(1) = "; W.print(); cout << endl;

	W.clearList();
	cout << "After clearList, W: "; W.print(); cout << "  isEmpty=" << W.isEmpty() << endl;

	cout << "W -> isEmpty(): " << W.isEmpty() << ", listSize(): " << W.listSize() << endl; // isEmpty? and listSize:

	linkedList<int> L;	// L for loss
	L = W;
	cout << "L = "; L.print(); cout << endl;




	cout << "Testing complexNumber with linkedList: " << endl;

	linkedList<complexNumber> C;
	complexNumber z1(3, 4), z2(1, -2);

	C.insertEnd(z1);
	C.insertEnd(z2);
	cout << "C: "; C.print(); cout << endl;	//operator <<
	cout << "isItemAt 0 Equal to z1: " << C.isItemAtEqual(0, z1) << endl; // operator==

	linkedList<complexNumber> D;
	D = C;	// operator=
	cout << "D after copying C over: "; D.print(); cout << endl;
	return 0;
}
