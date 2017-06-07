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
	Stack<char> s1(25);   //create stacks
	Stack<char> s2(25);
	Stack<char> s3(25);
	Stack<char> s4(25);
	int lengthString = 0;
	//int x = 0;
	char x = ' ';
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
			//x = c - '0';
			s1.push(c);   //push element to the stack
			count1++;
			}
		}
		while(!s1.isEmpty()){		 //reverse the stack
					c = s1.pop();
					s2.push(c);
	}
		while(!s3.isEmpty()){		 //reverse the stack
						c = s3.pop();
						s4.push(c);
		}


	cout << "postfix: ";

	while(!s2.isEmpty()){
		c = s2.pop();
		cout << c;
	}

	while(!s4.isEmpty()){
		c = s4.pop();
		cout << c;
		}

	cout << endl << "value: ";


	return 0;
}
