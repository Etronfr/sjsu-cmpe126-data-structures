/*
 * linkedList.h
 *
 *  Created on: Sep 30, 2025
 *      Author: Medic
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <iomanip>

using namespace std;

template <typename elemType>
class linkedList {
private:
	struct Node {
		elemType data;
		Node* next;
		Node(elemType d, Node* n = nullptr) {
			data = d;
			next = n;
		}
	};

	Node* head;
	int count;	// current size
	int capacity = 1000;	// max size

public:
	linkedList();

	~linkedList();


	// Functions
	bool isEmpty() const;
	bool isFull() const;
	int listSize() const;
	int maxListSize() const;
	void print() const;
	bool isItemAtEqual(int pos, elemType& value) const;
	void insertAt(int pos, elemType& value);
	void insertEnd(elemType& value);
	void removeAt(int pos);
	elemType retreiveAt(int pos) const;
	void replaceAt(int pos, elemType& value);
	void clearList();

	linkedList<elemType>& operator=(const linkedList<elemType>& x);
};

template <class elemType>
linkedList<elemType>::linkedList() {
	head = nullptr;
	count = 0;
}

template <class elemType>
linkedList<elemType>::~linkedList() {
	clearList();
}

template <class elemType>
bool linkedList<elemType>::isEmpty() const {
	return count == 0;
}

template <class elemType>
bool linkedList<elemType>::isFull() const {
	return count == capacity;
}

template <class elemType>
int linkedList<elemType>::listSize() const {
	return count;
}

template <class elemType>
int linkedList<elemType>::maxListSize() const {
	return capacity;
}

template <class elemType>
void linkedList<elemType>::print() const {
	cout << "{";
	Node* curr = head;
	while (curr != nullptr) {
		cout << curr->data;
		curr = curr->next;
		if (curr != nullptr) { cout << ", ";
		}
	}
	cout << "}";
}

template <class elemType>
bool linkedList<elemType>::isItemAtEqual(int pos, elemType& value) const {
	if (pos < 0 || pos >= count) {
		cerr << "Position out of range!" << endl;
		return false;
	}
	Node* curr = head;
	for (int i = 0; i < pos; i++) {
		curr = curr->next;
	}
	return curr->data == value;
}

template <class elemType>
void linkedList<elemType>::insertAt(int pos, elemType& value) {
	if (pos > count || pos < 0) { cerr << "Position out of range!" << endl;
	return;
	}
	if (pos == 0) {
		Node* newNode = new Node(value, head);
		head = newNode;
		++count;
		return;
	}

	Node* prev = head;
	for (int i = 0; i < pos - 1; i++) {
		prev = prev->next;		// getting to the node at position
	}

	Node* newNode = new Node(value, prev->next);
	prev->next = newNode;

	++count;
}

template <class elemType>
void linkedList<elemType>::insertEnd(elemType& value) {
	if(isFull()) {
		cerr << "List is full.. no room for insert" << endl;
		return;
	}

	insertAt(count, value);
}

template <class elemType>
void linkedList<elemType>::removeAt(int pos) {
	if (pos >= count || pos < 0) { cerr << "Position out of range!" << endl;
	return; }

	Node* tempNode = nullptr;

	if (pos == 0) {
		tempNode = head;
		head = head->next;
	}
	else {
		Node* curr = head;
		for (int i = 0; i < pos - 1; i++) {
			curr = curr->next;
		}
		tempNode = curr->next;
		curr->next = tempNode->next;
	}
	delete tempNode;
	--count;
}

template <class elemType>
elemType linkedList<elemType>::retreiveAt(int pos) const {
	if (pos >= count || pos < 0) { cerr << "Position out of range!" << endl;
	return elemType(); }

	Node* curr = head;
	for (int i = 0; i < pos; i++) {
		curr = curr->next;
	}
	return curr->data;
}

template <class elemType>
void linkedList<elemType>::replaceAt(int pos, elemType& value) {
	if (pos >= count || pos < 0) { cerr << "Position out of range!" << endl;
	return; }

	Node* curr = head;
	for (int i = 0; i < pos; i++) {
		curr = curr->next;
	}
	curr->data = value;
}

template <class elemType>
void linkedList<elemType>::clearList() {
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	count = 0;
}

template <class elemType>
linkedList<elemType>& linkedList<elemType>::operator=(const linkedList<elemType>& x) {
if (this != &x) {
	clearList();
	Node* curr = x.head;
	while(curr != nullptr) {
			insertEnd(curr->data);
			curr = curr->next;
	}
}
return *this;
}


#endif /* LINKEDLIST_H_ */
