/*
 * arrayList.h
 *
 *  Created on: Sep 22, 2025
 *      Author: Medic
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include <iostream>
using namespace std;

template <class elemType>
class arrayList {
private:
	elemType* theList;
	int length;
	int cap;


public:
	//constructors
	arrayList(int listSize = 100) {
		if (listSize <= 0) {
			cerr << "List size has to be more than zero" << endl;
			cap = 100;
		}
		else {
		cap = listSize;
		}
		length = 0;
		theList = new elemType[cap];

	}
	arrayList(arrayList& list) {
		cap = list.cap;
		length = list.length;
		theList = new elemType[cap];

		for(int i = 0; i < length; i++){
			theList[i] = list.theList[i];
		}
	}

	//destructor
	virtual ~arrayList() {
		delete[] theList;
	}

	bool isEmpty() const {
		return (length == 0);
	}
	bool isFull() const {
		return (length == cap);
	}
	int listSize() const {
		return length;
	}
	int maxListSize() const {
		return cap;
	}
	void print() const {
		for(int i = 0; i < length; i++) {
			cout << theList[i];
		}
	}
	bool isItemAtEqual(int pos, elemType& elem) const {
		if(pos<0 || pos>=length) {
			cerr << "Element out of bounds";
			return false;
		}
		return theList[pos] == elem;
	}

	void insert(elemType element) {
		if (length >= cap) {
			cerr << "Cannot insert into a full list." << endl;
			return;
		}
		theList[length] = element;
		length++;
	}
	void insertAt(int pos, elemType& elem) {
		if(pos<0 || pos>length){
			cerr << "Element can't be inserted out of bounds";
		}
		else if(isFull()){
			cerr << "List is full";
		}
		else{
			for(int i = length; i>pos; i--){
				theList[i] = theList[i-1];
			}
			theList[pos] = elem;
			length++;
		}
	}
	void insertEnd(elemType& elem) {
		if (isFull()) {
			cerr << "List is full." << endl;
		}
		else {
			theList[length++] = elem;
		}
	}
	void removeAt(int pos) {
		if (pos<0 || pos>length) {
			cerr << "Element can't be removed out of bounds";
		}
		else {
			for(int i = pos; i < length - 1; i++) {
				theList[i] = theList[i+1];
			}
			length--;
		}
	}
	elemType retrieveAt(int pos) {
		if (pos<0 || pos>length) {
			cerr << "Element being retrieved is out of bounds. Please enter a new position";
		}
		return theList[pos];
	}
	void replaceAt(int pos, elemType& elem) {
		if (pos<0 || pos>length) {
			cerr << "Element being replaced is out of bounds";
		}
		else {
			theList[pos] = elem;
		}
	}
	void clearList() {
	    length = 0;
	}

	// Lab 8

	// [LP]
	unsigned int seqSearchIter (elemType element) {
		for (int i = 0; i < length; i++) {
			if (theList[i] == element) {
				return i;
			}
		}
		cout << "Not in List" << endl;
		return -1;
	}
	// [HP]
	unsigned int seqSearchRec (elemType element, int i) {

		if (i == length) {
			return -1;	// if index reaches the end and hasn't found it
		}
		else if (theList[i] == element) {
			return i;
		}
		return seqSearchRec(element, i + 1);
	}

};

#endif /* ARRAYLIST_H_ */
