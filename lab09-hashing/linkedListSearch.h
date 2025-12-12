/*
 * linkedListSearch.h
 *
 *  Created on: Nov 22, 2025
 *      Author: Medic
 */

#ifndef LINKEDLISTSEARCH_H_
#define LINKEDLISTSEARCH_H_
#include <iostream>

using namespace std;

// HP: Implement task 1 using template format.

template <class elemType>
class linkedListSearch {
private:
    struct node {
        elemType elem;
        node* nN; //new node

        node(const elemType& e, node* n = nullptr){
        	elem = e;
        	nN = n;
        }
    };

    node* head;
    int count;
    int cap = 1000; // Maximum possible size for isFull() check

public:
    // Constructors
    linkedListSearch();

    // Destructor
    ~linkedListSearch();

    // Assignment operator
    linkedListSearch<elemType>& operator=(const linkedListSearch<elemType>& other);

    // Basic operations
    bool isEmpty() const;
    bool isFull() const;
    int listSize() const;
    int maxListSize() const;

    // Display and utility functions
    void print() const;

    // Item operations
    bool isItemAtEqual(int pos, const elemType& e) const;
    void insertAt(int pos, const elemType& e);
    void insert(elemType element);
    void insertEnd(const elemType& e);
    void removeAt(int pos);
    elemType retrieveAt(int pos) const;
    void replaceAt(int pos, const elemType& e);
    void clearList();
    int seqSearchIter(elemType element);
    int seqSearchRecHelp(elemType element, node* curr, int index);
    int seqSearchRec(elemType element);
};


template <class elemType>
linkedListSearch<elemType>::linkedListSearch() {
	head = nullptr;
	count = 0;
}

template <class elemType>
linkedListSearch<elemType>::~linkedListSearch() {
	clearList();
}

template <class elemType>
bool linkedListSearch<elemType>::isEmpty() const{
	return count == 0;
}

template <class elemType>
bool linkedListSearch<elemType>::isFull() const {
	return count >= cap;
}

template <class elemType>
int linkedListSearch<elemType>::listSize() const {
	return count;
}

template <class elemType>
int linkedListSearch<elemType>::maxListSize() const {
	return cap;
}

template <class elemType>
void linkedListSearch<elemType>::print() const {
	node* current = head;
	if(isEmpty()){
		cout << "Empty list" << endl;
	}
	while(current != nullptr){
		cout << current->elem << " ";
		current = current->nN;
	}
	cout << endl;
}

template <class elemType>
bool linkedListSearch<elemType>::isItemAtEqual(int pos, const elemType& e) const{
	if(pos<0 || pos>=count){
		cerr << "Attempting to compare out of bound element" << endl;
		return false;
	}
	node* current = head;
	for (int i = 0; i < pos; i++) {
	    current = current->nN;
	}
	return current->elem == e;
}

template <class elemType>
void linkedListSearch<elemType>::insert(elemType element) {
    if (isFull()) {
        cerr << "Can't insert into a full list" << endl;
        return;
    }
    node* newNode = new node(element);
    if (isEmpty()) {
        head = newNode;
    }
    else {
        node* current = head;
        while (current->nN != nullptr) {
            current = current->nN;
        }
        current->nN = newNode;
    }
    count++;
}
template <class elemType>
void linkedListSearch<elemType>::insertAt(int pos, const elemType& e){
	if(pos<0 || pos>count){
		cerr << "Attempting to insert element out of bounds" << endl;
		return;
	}

	if(pos == 0){
		head = new node(e, head);
	}
	else{
		node* current = head;
		for (int i = 0; i < pos - 1; i++) {
		    current = current->nN;
	    }
	    current->nN = new node(e, current->nN);
	}
	count++;
}

template <class elemType>
void linkedListSearch<elemType>::insertEnd(const elemType& e){
	if(isFull()){
		cerr << "Attempting to add to a full list" << endl;
		return;
	}

	insertAt(count, e);
}

template <class elemType>
void linkedListSearch<elemType>::removeAt(int pos){
	if(isEmpty()){
		cerr << "Attempting to remove an element from an empty list" << endl;
		return;
	}
	if(pos<0 || pos>=count){
		cerr << "Attempting to remove element from an invalid location" << endl;
		return;
	}

	node* tempNode;
	if (pos == 0) {
	        tempNode = head;
	        head = head->nN;
	}
	else{
	    node* current = head;
	    for (int i = 0; i < pos - 1; i++) {
	        current = current->nN;
	    }
	    tempNode = current->nN;
	    current->nN = tempNode->nN;
	}
	delete tempNode;
	count--;
}

template <class elemType>
elemType linkedListSearch<elemType>::retrieveAt(int pos) const{
	if(pos<0 || pos>=count){
		cerr << "Attempting to retrieve from an invalid position" << endl;
		return elemType();
	}

	if(isEmpty()){
		cerr << "Attempting to retrieve from an empty list" << endl;
		return elemType();
	}

	node* current = head;
	for (int i = 0; i < pos; i++) {
		current = current->nN;
	}
    return current->elem;
}

template <class elemType>
void linkedListSearch<elemType>::replaceAt(int pos, const elemType& e){
	if(pos<0 || pos>=count){
		cerr << "Attempting to replace an element in an out of bounds location" << endl;
		return;
	}

	node* current = head;
    for (int i = 0; i < pos; i++) {
        current = current->nN;
    }

    current->elem = e;
}

template <class elemType>
void linkedListSearch<elemType>::clearList(){
	while (head != nullptr) {
        node* temp = head;
        head = head->nN;
        delete temp;
    }
	count = 0;
}

template <class elemType>
linkedListSearch<elemType>& linkedListSearch<elemType>::operator=(const linkedListSearch<elemType>& other){
	if(this != &other){
		clearList();
		node* current = other.head;
		while(current != nullptr){
			insertEnd(current->elem);
			current = current->nN;
		}
	}
	return *this;
}

//LAB 8

// [LP]
template <class elemType>
int linkedListSearch<elemType>::seqSearchIter(elemType element) {
	node* curr = head;
	int index = 0;
	while(curr != nullptr) {
		if (curr->elem == element) {	// elem is data, element is given value to find
			return index;
		}
		else {
			curr = curr->nN;
			index++;
		}
	}
	return -1;	//-1 means not found
}

// [HP]
template <class elemType>
int linkedListSearch<elemType>::seqSearchRecHelp(elemType element, node* curr, int index) {

	if(curr == nullptr) {
		return -1; //element not in list
	}
	else if (curr->elem == element) {
		return index;
	}
	return seqSearchRecHelp(element, curr->nN, index + 1);
}

template <class elemType>
int linkedListSearch<elemType>::seqSearchRec(elemType element) {
    return seqSearchRecHelp(element, head, 0);
}




#endif /* LINKEDLISTSEARCH_H_ */
