//============================================================================
// Name        : q5postfixNotation.cpp
// Author      : Marius Popescu
// CS300 - Assignment3
// Question 5
// Description : This program will read a string as a expression in infix format
// will print the expression in postfix notation, and then evaluate the expression
// by using only stacks.
//============================================================================

#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

int main() {
	string expression;
	Stack<int> s1(25);   //create stacks
	Stack<int> s2(25);
	Stack<char> s3(25);
	int lengthString = 0;
	int x = 0;
	char c = ' ';
	char d = ' ';
	int count1 = 0;
	int count2 = 0;
	cout << "Enter a expression: " << endl; // prompt the user for a expression
	cin >> expression;
	lengthString = expression.length();
	for (int i = 0; i <= lengthString; i++){
		c = expression[i];
		if(c == '+' || c == '*'){
			s3.push(c);   //push element to the stack
			count2++;
		}
		else{
			x = c - '0';
			s1.push(x);   //push element to the stack
			count1++;
			}
		for(int i = 0; i < count1; i++){
			x = s1.pop();
			s2.push(x);
		}
	}
	s1.pop();      //first pop the null element
	s3.pop();

	cout << "postfix: ";

	for (int i = 0; count1; i++){
		x = s2.pop();
		cout << x;
	}
	for (int i = 0; count1; i++){
		d = s3.pop();
		cout << d;
		}
	cout << "value: ";


	return 0;
}
