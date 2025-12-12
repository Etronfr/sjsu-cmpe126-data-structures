/*
 * palindrome.cpp
 *
 *  Created on: Oct 13, 2025
 *      Author: Medic
 */

#include <iostream>
#include <cmath>
using namespace std;

bool checkPalindrome(const int &n) {
    cout << "Checking " << n << endl;

    // Base case
    if (n >= 0 && n < 10) {
        cout << "Returning true (single digit)" << endl;
        return true;
    }

    int digits = log10(n);
    int first = n / pow(10, digits);
    int last = n % 10;

    cout << "First: " << first << ", Last: " << last << endl;

    if (first != last) {
        cout << "Returning false" << endl;
        return false;
    }

    int remaining = (n % (int)pow(10, digits)) / 10;

    cout << "Recurse on " << remaining << endl;

    return checkPalindrome(remaining);
}

