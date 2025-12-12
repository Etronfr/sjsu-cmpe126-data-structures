//============================================================================
// Name        : lab6-cmpe126.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>
using namespace std;

bool isOp(char c) {	// c = character
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int pemdas(char op) { // checks precedence keeping pemdas in check!
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}

string infixToPostfix(const string& infix) {
	string postfix;
	stack<char> st;

for (char symbol : infix) {
	if (isspace(symbol)) continue;

	if (isalpha(symbol)) {
		postfix = postfix + symbol;
		postfix = postfix + ' ';
	}
	else if (symbol == '(') {	// Push parentheses
		st.push(symbol);
	}
	else if (symbol == ')') {
		while (!st.empty() && st.top() != '(') {
			postfix += st.top();
			postfix += ' ';
			st.pop();
	}
	if (!st.empty() && st.top() == '(') st.pop();
	}

	else if (isOp(symbol)) {	// Check if symbol is an operator
		while (!st.empty() && st.top() != '(' ) {
			char popped = st.top(); st.pop();	//pop operator from stack

			if (pemdas(popped) >= pemdas(symbol)) {
				postfix += popped; postfix += ' ';
			}
			else {
				st.push(popped);	//push operater back on stack, push symbol, then break
				st.push(symbol);
				goto next_char;
			}
		}
		st.push(symbol);
	}
	next_char: ;
	}

	while (!st.empty()) {	//while the stack isnt empty pop the operator
		if (st.top() != '(') {
			postfix += st.top();
			postfix += ' ';
		}
		st.pop();
	}
	if (!postfix.empty() && postfix.back() == ' ') postfix.pop_back();
	return postfix;
}

// TASK 2 (Two HP)

double evaluatePostFix(const string& postfix) {
	stack<double> st;
	string bread;	//token holds input
	stringstream ss(postfix);

	while (ss >> bread) {
		if (!(bread.size() == 1 && (bread == "+" || bread == "-" || bread == "*" || bread == "/"))) {
			st.push(stod(bread));
		}
		else {
			if (st.size() < 2) throw runtime_error("Bad postfix: too few operands");
			double n2 = st.top();	//Pop from stack n1 and n2
			st.pop ();

			double n1 = st.top();
			st.pop();

			double result = 0.0;

			if (bread == "+") {
				result = n1 + n2;
			}
			else if (bread == "-") {
				result = n1 - n2;
			}
			else if (bread == "*") {
				result = n1 * n2;
			}
			else if (bread == "/") {
				if (n2 == 0.0) throw runtime_error("Division by zero");
				result = n1 / n2;
			}

			st.push(result); // push result on stack
		}
	}

	if (st.size() != 1) throw runtime_error("Bad Postfix: leftover on stack");

	return st.top(); // return final resulttt
	}


int main() {
	vector<string> infixTests = {
		"A + B - C",
		"(A + B) * C",
		"(A + B) * (C - D)",
		"A + ((B + C) * (E - F) - G) / (H - I)",
		"A + B * (C + D) - E / F * G + H"
	};
	for (int i = 0; i < infixTests.size(); i++) {
		string t = infixTests[i];
		cout << "Infix: " << t << "  to -> Postfix: " << infixToPostfix(t) << endl;
	}
	cout << endl;


	// HP test task 2
	cout << evaluatePostFix("2 10 5 * +") << endl;
	cout << evaluatePostFix("3.5 -2 * 4 +") << endl;

	return 0;
}
