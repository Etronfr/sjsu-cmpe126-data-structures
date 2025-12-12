/*
 * arrayList.cpp
 *
 *  Created on: Sep 24, 2025
 *      Author: Medic
 */
/*
#include <iostream>
#include "arrayList.h"
using namespace std;


//LP Functions
arrayList::arrayList(int listSize){
	if(listSize <= 0){
		cerr << "List size has to be greater than zero" << endl;
		cap = 1000;
	}
	cap = listSize;
	length = 0;
	theList = new complexNumber[cap];

}

arrayList::arrayList(arrayList& list){
	cap = list.cap;
	length = list.length;
	theList = new complexNumber[cap];

	for(int i=0; i<length;i++){
		theList[i] = list.theList[i];
	}
}

arrayList::~arrayList(){
	delete[] theList;
}

bool arrayList::isEmpty() const{
	return (length == 0);
}

bool arrayList::isFull() const{
	return (length == cap);
}

int arrayList::listSize() const{
	return length;
}

int arrayList::maxListSize()const{
	return cap;
}

void arrayList::print() const{
	for(int i=0; i<length; i++){
		cout << theList[i];
	}
	cout << endl;
}

bool arrayList::isItemAtEqual(int pos, complexNumber& elem) const{
	if(pos<0 || pos>=length){
		cerr << "Element out of bounds";
		return false;
	}
	return(theList[pos] == elem);
}

// HP Functions

void arrayList::insertAt(int pos, complexNumber& elem){
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

void arrayList::insertEnd(complexNumber& elem){
	if(isFull()){
		cerr << "List is full." << endl;
	}
	else{
		theList[length++] = elem;
	}
}

void arrayList::removeAt(int pos){
	if(pos<0 || pos>length){
		cerr << "Element can't be removed out of bounds";
	}
	else{
		for(int i=pos; i<length-1;i++){
			theList[i] = theList[i+1];
		}
		length--;
	}
}

complexNumber arrayList::retrieveAt(int pos){
	if(pos<0 || pos>length){
		cerr << "Element being retrieved is out of bounds. Please enter a new position";
	}
	return theList[pos];
}

void arrayList::replaceAt(int pos, complexNumber& elem){
	if(pos<0 || pos>length){
		cerr << "Element being replaced is out of bounds";
	}
	else{
		theList[pos] = elem;
	}
}

void arrayList::clearList(){
    length = 0;
}

//Lab 8

unsigned int arrayList::seqSearchIter (elemType element) {

}
unsigned int arrayList::seqSearchRec (elemType element) {

};
*/
