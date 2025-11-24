/*
 * complexnum.h
 *
 *  Created on: Oct 6, 2025
 *      Author: Medic
 */

#ifndef COMPLEXNUM_H_
#define COMPLEXNUM_H_
#include <iostream>
#include <cmath>

using namespace std;

class complexNumber {

	private:
		double im;
		double real;

	public:
	complexNumber();
	complexNumber(double a);
	complexNumber(double a, double b);

	void setReal(double r);
	void setIm(double i);

	double getReal() const;
	double getIm() const;

	double getModulus();

	void print() const;
	bool operator==(const complexNumber& other) const;

	};

	complexNumber operator+(const complexNumber& lhs, const complexNumber& rhs);
	complexNumber operator-(const complexNumber& lhs, const complexNumber& rhs);
	complexNumber operator*(const complexNumber& lhs, const complexNumber& rhs);
	ostream& operator<<(ostream& o, const complexNumber& x); //o = output, x = number
	istream& operator>>(istream& in, complexNumber& x);




#endif /* COMPLEXNUM_H_ */
