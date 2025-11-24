/*
 * complexnum.cpp
 *
 *  Created on: Oct 6, 2025
 *      Author: Medic
 */

#include "complexNumber.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

	complexNumber::complexNumber() {
		real = 0.0, im = 0.0;
	}
	complexNumber::complexNumber(double a, double b) {
		real = a, im = b;
	}
	complexNumber::complexNumber(double a) {
			real = a;
			im = 0.0;
	}

	void complexNumber::setReal(double r) { real = r; }
	void complexNumber::setIm(double i) { im = i; }

	double complexNumber::getReal() const { return real; }
	double complexNumber::getIm() const { return im; }

	double complexNumber::getModulus() {
		return sqrt((real * real) + (im * im));
	}

	void complexNumber::print() const{
		cout << real << " + i"<< im << endl;
	}
	bool complexNumber::operator==(const complexNumber& other) const {
	    return real == other.getReal() && im == other.getIm();
	}

	complexNumber operator+(const complexNumber& lhs, const complexNumber& rhs) {
			return complexNumber(lhs.getReal() + rhs.getReal(), lhs.getIm() + rhs.getIm());
		}
	complexNumber operator-(const complexNumber& lhs, const complexNumber& rhs) {
		return complexNumber(lhs.getReal() - rhs.getReal(), lhs.getIm() - rhs.getIm());
			}
	complexNumber operator*(const complexNumber& lhs, const complexNumber& rhs) {
		double a = lhs.getReal(), b = lhs.getIm();
		double c = rhs.getReal(), d = rhs.getIm();
		return complexNumber(a * c - b * d, a * d + b * c);
				}
	ostream& operator<<(ostream& o, const complexNumber& x) {
	    o << x.getReal();
	    if (x.getIm() < 0) {
	        o << x.getIm() << "i";
	    }
	    else
	        o << "+" << x.getIm() << "i";
	    return o;
	}
	istream& operator>>(istream& in, complexNumber& x) {
		string s; //number string is s
		if (!(in >> s)) return in;

		if (s.size() < 2 || s.back() != 'i') {
			in.setstate(ios::failbit); // wrong format not inluding i then fail
			return in;
		}
		s.pop_back(); // get rid of i

		int split = -1;
		for (int i = (int)s.size() - 1; i >= 1; --i ) {
			if (s[i] == '+' || s[i] == '-') { // go through string starting from back to find the sign
				split = i; break;
			}
		}
			if (split == -1) {
				in.setstate (ios::failbit); // if the function finding the sign never was true then fail
				return in;
			}
			string realstr = s.substr(0, split); // copy string from beginning to sign
			string imstr = s.substr(split); // copy string starting from sign to the end of string

			double r;
			double im;
			{
				istringstream rs(realstr);
				if (!(rs >> r) || !rs.eof()) {
					in.setstate(ios::failbit); //if cant copy string into r then fail
					return in;
				}
			}
			{
				istringstream is(imstr);
				if (!(is >> im) || !is.eof()) {
					in.setstate(ios::failbit); // if cant copy string into im then fail
					return in;
				}

		}
			x.setReal(r);
			x.setIm(im);
			return in;
	}
