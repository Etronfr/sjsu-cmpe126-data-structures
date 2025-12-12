/*
 * sortedarrayList.h
 *
 *  Created on: Nov 11, 2025
 *      Author: Medic
 */

#ifndef SORTEDARRAYLIST_H_
#define SORTEDARRAYLIST_H_

#include <iostream>
using namespace std;

// [HP]
template <class elemType>
class sortedarrayList {

private:

elemType* list;
int size;	//current size of array
int cap;

public:
//constructor
sortedarrayList(int listSize = 100) {
	cap = listSize;
	size = 0;
	list = new elemType[cap];
}

//deconstructor
~sortedarrayList(){
	delete[] list;
}

bool isEmpty() const {
	return size == 0;
}

bool isFull() const {
	return size == cap;
}

int listSize() const {
	return size;
}

int maxListSize() const {
	return cap;
}

void print() const {
	for (int i = 0; i < size; i++) {
		cout << list[i] << endl;
	}
}

bool insert(elemType value) {
	if (isFull()) {
		cerr << "Array is full cannot insert" << endl;
		return false;
	}
	int insertPos = 0;
	for (; (insertPos < size && list[insertPos] < value); insertPos++);
	for (int i = size; i > insertPos; i--) {
		list[i] = list[i - 1];
	}
	list[insertPos] = value;
	size++;
	return true;
}

void remove(elemType value) {
	if (isEmpty()) {
		cerr << "Array is empty so nothing to be removed" << endl;
		return;
	}
	int removePos = -1;
	for (int i = 0; i < size; i++) {
		if (list[i] == value) {
			removePos = i;
		}
	}

	if (removePos == -1) {
		cerr << "Value was not found in the list." << endl;
		return;
	}

	for (int i = removePos; i < size - 1 ; i++) {
			list[i] = list[i + 1];
		}
	size--;
}

void clearList() {
	size = 0;
}

// [HP]
unsigned int binarySearchIter (elemType element) {
	int first = 0;
	int last = size - 1;

	while (first <= last) {
		int mid = (first + last) / 2;

	if (list[mid] == element) {
		return mid;
	}

	if (list[mid] < element) {
		first = mid + 1;
	}
	else {
		last = mid - 1;
		}
	}
	return -1; // element was not found
}

// [HP]
unsigned int binarySearchRec (elemType element, int first, int last) {
	if (first <= last) {
		int mid = (first + last) / 2;

		if (list[mid] == element) {
			return mid;
		}

		if (list[mid] < element) {
			return binarySearchRec(element, mid + 1, last);
		}
		return binarySearchRec(element, first, mid - 1);
		}
	return -1; // element was not found
	}

};

#endif /* SORTEDARRAYLIST_H_ */
