/*
 * Padovan.cpp
 *
 *  Created on: Oct 13, 2025
 *      Author: Medic
 */

#include <iostream>
using namespace std;

unsigned int padovan(const unsigned int &n) {
	cout << "In Padovan with n = " << n << endl;

	if (n == 0 || n == 1 ||  n == 2) {
		cout << "Returning 1 with n = " << n << endl;
        return 1;
    }

    unsigned int p = padovan(n - 2) + padovan(n - 3);

    cout << "Returning " << p << " with n = " << n << endl;

    return p;
}


