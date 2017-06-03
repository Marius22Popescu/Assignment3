//============================================================================
// Name        : Question4eEclipse.cpp
// Author      : Marius Popescu
// Description : This function will add very large numbers, for this reason we
// used strings and stacks. First stack will hold first number second stack will
// hold the second number and the third stack will hold the result of addition.
//============================================================================

#include <iostream>
#include "Stack.h"
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

void add(string a, string b);

int main()
{
	add("1876543217", "8292");
}

void add(string a, string b)
{
	Stack<int> s1(25);  //create stacks
	Stack<int> s2(25);
	Stack<int> s3(26);
	int nr = 0;
	int lengthA = a.length();     //assign a variable for the length of the first string
	int lengthB = b.length();	  //assign a variable for the length of the second string
	for (int i = 0; i <= lengthA; i++){
		nr = a[i];
		s1.push(nr);   //push first number to the stack
	}
	for (int i = 0; i <= lengthB; i++){
		nr = b[i];
		s2.push(nr);    //push second number to the stack
	}

	char x, y;
	int i, j, k, m, rem;
	s1.pop();      //first pop the null element
	s2.pop();
	rem = 0;
	m = 0;
	int maxLength;                //find the maximum length between numbers in order to set the for loop in order to perform addition
	if (lengthA > lengthB)
		maxLength = lengthA;
	else
		maxLength = lengthB;
	cout << "sum = ";
	for(int q = 0; q < maxLength; q++){
		if(!s1.isEmpty()){
		x = s1.pop();
		i = x - '0';            //converting from char to integer
		}
		else
		i = 0;                  //to avoid errors if in the stack will be no more elements we will set i = 0
		if(!s2.isEmpty()){
		y = s2.pop();
		j = y - '0';             //converting from char to integer
		}
		else
		j = 0;					//to avoid errors if in the stack will be no more elements we will set i = 0
		k = i + j;				//perform the addition

		if (k<10){
			m = k + rem;
			s3.push(m);         //push to the stack 3
			rem = 0;
		}
		else {
			k = k % 10;
			m = k + rem;
			s3.push(m);         //push to the stack 3
			rem = 1;
		}
	}
	while (!s3.isEmpty()){      //pop the elements from the stack 3 and display the result of addition
		k = s3.pop();
		cout << k;
	}
}
