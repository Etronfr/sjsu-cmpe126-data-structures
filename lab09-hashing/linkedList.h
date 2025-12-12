/*
 * linkedList.h
 *
 *  Created on: Nov 18, 2025
 *      Author: Medic
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
using namespace std;

class linkedList {
private:
	struct Node {
		int data;
		Node* next;
		Node(int d, Node* n = nullptr) {	//Node Constructor
			data = d;	//value want in node
			next = n;	//ptr to next node
		}
	};
	Node* head;

public:
	linkedList() {
		head = nullptr; //initialize linkedList starting empty
	}
	~linkedList() {
		Node* curr = head;	//start at head
		while (curr != nullptr) {	//while current node is not empty
			Node* temp = curr;
			curr = curr->next;
			delete temp;
		}
	}

	void bucketPrint() {
		Node* curr = head;
		while (curr != nullptr) {
			cout << "[" << curr->data << "]";
			curr = curr->next;
		}
		cout << endl;
	}

	void bucketInsert(int key) {
		Node* newNode = new Node(key);
		if (head == nullptr) {
			head = newNode;
		}
		else {
		Node* curr = head;
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = newNode;
	}
}
	bool bucketSearch(int key) {	//element, bucket
		Node* curr = head;
		if (head == nullptr) { return false; }	//for insert when searching duplicates so no error
		while (curr != nullptr) {
			if (curr->data == key) {
				return true;
			} else {
			curr = curr->next;
			}
		}
	return false;
	}

	bool isEmpty() {
		return head == nullptr;
	}

	bool bucketRemove(int key) {
		if (head == nullptr) { return false; }
		Node* prev = head;
		Node* curr = head->next;	//since head is checked itself, start after head
		if (head->data == key) {	//remove head if nothing else in list
			Node* temp = head;
			head = head->next;
			delete temp;
			return true; }
		while (curr != nullptr) {
			if (curr->data == key) {
				prev->next = curr->next;	//Adjust pointers
				delete curr;
				return true;
			}
			else {
				prev = prev->next;
				curr = curr->next;
			}
		}
		return false;
	}
};




#endif /* LINKEDLIST_H_ */
