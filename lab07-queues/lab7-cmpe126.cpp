//============================================================================
// Name        : lab7-cmpe126.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "arrayQueue.h"

using namespace std;

int main() {
	try{
		arrayQueue<char> q1;
		q1.enqueue('A');
		q1.enqueue('B');
		cout << q1.dequeue() << endl;
		q1.enqueue('C');
		cout << q1.dequeue() << endl;
		q1.enqueue('D');
		cout << q1.dequeue() << endl;
		cout << q1.dequeue() << endl;
		cout << q1.dequeue() << endl;
	}

	catch(const char *e) {
		cout << e << endl;
	}

	try{
		arrayQueue<int> q2(2);
		q2.enqueue(1);
		q2.enqueue(2);	// Throwing Queue is full
		q2.enqueue(3);
	}
	catch(const char *e) {
		cout << e << endl;
	}

	try{
		arrayQueue<char> q3(3);
		q3.enqueue('A'); q3.enqueue('B');
		cout << "Front = " << q3.front() << ", size = " << q3.size() << "\n";
		cout << q3.dequeue() << endl;
	}
	catch(const char *e) {
		cout << e << endl;
	}


	try{
		arrayQueue<char> q4(69);
		q4.maxSize();
		q4.isEmpty();

	}
	catch(const char *e) {
		cout << e << endl;
			}
return 0;
}

