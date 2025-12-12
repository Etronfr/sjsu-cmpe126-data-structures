/*
 * arrayQueue.h
 *
 *  Created on: Oct 30, 2025
 *      Author: Medic
 */

#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_

#include <iostream>
using namespace std;

template <typename Q>
class arrayQueue {

private:
	Q* data;
	int frontOf;	//front element
	int backOf;		//element in back
	int count;
	int maxsize;


public:

	arrayQueue(int capacity = 100) {
		maxsize = capacity;
		data = new Q[maxsize];
		frontOf = 0;
		backOf = -1;
		count = 0;
	}

	~arrayQueue() {
		delete[] data;
	}

	void enqueue(const Q& element) {	// add element in back of queue
		if (isFull()) throw "Queue is FULL";
		backOf = (backOf + 1) % maxsize;	// circular loop
		data[backOf] = element;
		count++;
	}

	Q dequeue() {	// remove element from front of queue
		if (isEmpty()) throw "Queue has no elements so you cannot dequeue anything.";
		Q value = data[frontOf];
		frontOf = (frontOf + 1) % maxsize;
		count--;
		return value;
	}

	Q front() const {	// return fron element
		if (isEmpty()) throw "Queue is empty.";
		return data[frontOf];
	}

	int size() const {	// retrieve size of queue
		return count;
	}

	bool isEmpty() const {	// check if queue is empty
		return count == 0;
	}

	bool isFull() const{	// check if queue is full
		return count == maxsize;
	}

	int maxSize() const {	// retrieve max size of queue
		return maxsize;

	}

};


#endif /* ARRAYQUEUE_H_ */
