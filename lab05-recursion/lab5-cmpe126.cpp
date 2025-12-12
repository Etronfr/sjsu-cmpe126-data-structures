//============================================================================
// Name        : lab5-cmpe126.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
unsigned int padovan(const unsigned int &n);
bool checkPalindrome(const int &n);
int main() {

	// Padovan test
	unsigned int n1 = 5;
	cout << "Padovan: " << endl;
	cout << "padovan n1 = 5: " << endl;

	padovan(n1);

	// Palindrome test
	int num1 = 12321;
	cout << "\n" "\n" "Palindrome: " << endl;
	cout << "Checking if " << num1 << " is a palindrome: ";
	cout << (checkPalindrome(num1) ? "Yes" : "No") << endl;

	int num2 = 12341;

	cout << "Checking if " << num2 << " is a palindrome: ";
	cout << (checkPalindrome(num2) ? "Yes" : "No") << endl;
	return 0;
}
