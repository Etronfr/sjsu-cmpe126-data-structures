/*
 * hashtable.h
 *
 *  Created on: Nov 15, 2025
 *      Author: Medic
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <iostream>
using namespace std;

class HashTable {	//LINEAR PROBING [LP]
private:
	int *HashArr;	//Hash Array
	int HTSize; // MaxSize of hash table

public:				// -1 means empty, -2 means deleted, any other value means occupied
	//Constructor
	HashTable(int listSize = 100) {
		HTSize = listSize;
		HashArr = new int[HTSize];
		for (int i = 0; i < HTSize; i++) {	//-1 means empty; easy way to check if index is empty
			HashArr[i] = -1;
		}
}

	~HashTable() {
		delete[] HashArr;
	}

	void print() {
		for (int i = 0; i < HTSize; i++) {
			if (HashArr[i] == -1) {
				cout << "[x]";
			}
			else if (HashArr[i] == -2) {
				cout << "[DELETED]";
			}
			else {
			cout << "[" << HashArr[i] << "]";
			}
		}
		cout << endl;
	}


	bool insert(int key) {	//key = value we're inserting
		int HIndex = key % HTSize;	//set Hash Index
		int probeCount = 0;
		int tombStone = -1;		//Tombstone for a removed item, but keep searching for real empty (-1) in case of duplicate ahead
		while(HashArr[HIndex] != -1) {
			probeCount++;
			if (HashArr[HIndex] == key) {
				cout << "Duplicates Not Accepted." << endl;
				return false;
			}
			if (probeCount == HTSize) {
				if (tombStone != -1) {	//Before calling full, if no empty is met, but tombstone exists
					HashArr[tombStone] = key;
					cout << "Input at Index: " << tombStone << endl;
					return true;
				} else {
				cout << "HashTable is Full, cannot insert anything." << endl;
				return false;
				}
			}
			if (HashArr[HIndex] == -2) {
				if (tombStone == -1) {	// tombStone == -1 means no tombStone found yet. Only taking the first found tombstone
				tombStone = HIndex;
				}
			}
			HIndex = (HIndex + 1)% HTSize;
		}
		if (tombStone != -1) {	//If Tombstone == -1 then there is no tombstone
			HashArr[tombStone] = key;
			cout << "Input at Index: " << tombStone << endl;
			return true;
		}
		else {
			HashArr[HIndex] = key;
			cout << "Input at Index: " << HIndex << endl;
			return true;
		}
		return false;
	}

	int search(int key) {
		int HIndex = key % HTSize;	//set Hash Index
		int probeCount = 0;
		while(HashArr[HIndex] != -1) {	//while not empty loop
			if (HashArr[HIndex] == key) {
				cout << "Key found at Index: " << HIndex << endl;
				return 1;
			}
			HIndex = (HIndex + 1) % HTSize;
			probeCount++;
			if (probeCount == HTSize) {
				cout << "Key not found in HashTable " << endl;
				return -1;
			}
		}
		return 0;
	}
	//[HP]
	bool remove(int key) {
		int HIndex = key % HTSize;	//set Hash Index
		int probeCount = 0;
		while(HashArr[HIndex] != -1) {	//while not empty loop
			if (HashArr[HIndex] == key) {
				HashArr[HIndex] = -2;
				cout << "Key removed at Index: " << HIndex << endl;
				return true;
			}
			HIndex = (HIndex + 1) % HTSize;
			probeCount++;
			if (probeCount == HTSize) {
				cout << "Key isn't in HashTable " << endl;
				return false;
			}
		}
		return false;
	}

};



#endif /* HASHTABLE_H_ */
