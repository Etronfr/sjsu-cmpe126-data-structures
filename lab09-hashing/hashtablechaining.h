/*
 * hashtablechaining.h
 *
 *  Created on: Nov 16, 2025
 *      Author: Medic
 */

#ifndef HASHTABLECHAINING_H_
#define HASHTABLECHAINING_H_

#include <iostream>
#include "linkedList.h"
using namespace std;

class HashTableChaining {	//[LP]
private:
	static const int bucketNum = 10;	//Number of buckets (Hash Table Size) // Static array
	linkedList buckets[bucketNum]; //Array with linkedLists


public:
	void print() {
		for (int i = 0; i < bucketNum; i++) {
			buckets[i].bucketPrint();
		}
	}

	void insert(int key) {	//insert elem into linked list *no duplicates *no limit on linked lists
		if (buckets[findHIndex(key)].bucketSearch(key)) {
			cout << "Duplicates Not Accepted." << endl;
			return;
		} else {
		buckets[findHIndex(key)].bucketInsert(key);
		return;
		}
	}

	void search(int key) {
		int HIndex = findHIndex(key);
		if (buckets[HIndex].isEmpty()) {
			cout << "Bucket is Empty." << endl;
		}
		else if (buckets[HIndex].bucketSearch(key)) {
			cout << key << " was found in bucket: " << HIndex << endl;
		}
		else {
			cout << "Key was not found in bucket." << endl;
		}
		return;
	}


	int findHIndex(int key) {
		int HIndex;
		HIndex = key % bucketNum;
		return HIndex;
	}
	//[HP]
	bool remove(int key) {
		int HIndex = findHIndex(key);
		if (buckets[HIndex].isEmpty()) {
			cout << "Element not In Bucket" << endl;
			return false;
		}
		else if (buckets[HIndex].bucketRemove(key)) {
			cout << key << " was removed in bucket: " << HIndex << endl;
			return true;
		}
		else {
			cout << "Key was not found in bucket." << endl;
			return false;
		}
	}

};





#endif /* HASHTABLECHAINING_H_ */
