/*
 * arrayList.h
 *
 *  Created on: Sep 22, 2025
 *      Author: Medic
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

template <typename elemType>

class arrayList {
private:
	elemType* data = NULL; // dynamic array [HP]
	int count;	// current size
	int capacity; // the max array size


public:
	arrayList(int max = 100) { //constructor
		capacity = max;
		count = 0;
		data = new elemType[capacity];
	}
	~arrayList() {	// deconstructor
		delete[] data;
	}

	bool isEmpty() const {
		return count == 0;
	}
	bool isFull() const {
		return count == capacity;
	}

	int listSize() const {
		return count;
	}

	int maxListSize() const {
		return capacity;
	}

	void print() {
		cout << "[" ;
		for (int i = 0; i < count; i++) {
			cout << data[i] << ", ";
		}
		cout << "]" << endl;
	}

	bool isItemAtEqual(int pos, elemType value) {
		return (pos < count && data[pos] == value);
	}

	// [HP] Functions

	void insertAt(int pos, elemType value) {
		if (isFull() || pos < 0 || pos > count) {
			cout << "Position out of range" << endl;
			return;
		}

		for (int i = count; i > pos; i--) {
			data[i] = data[i - 1];
		}
		data[pos] = value;
		count++; // because the current size increased
	}

	void insertEnd(elemType value) {
		if (isFull()) return;
		data[count] = value;
		count++;
	}
	void removeAt(int pos) {
		if (count == 0 || pos < 0 || pos >= count) {
			cout << "Position out of range" << endl;
			return;
		}
		for (int i = pos; i < count - 1; i++) {
			data[i] = data[i +1];
		}
		count--;
	}

	elemType retrieveAt(int pos) {
		if (pos < 0 || pos >= count) {
			throw out_of_range("Position Out of Range!");
		}
		return data[pos];
	}
};





#endif /* ARRAYLIST_H_ */
