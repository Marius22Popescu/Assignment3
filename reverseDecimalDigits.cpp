//============================================================================
// Name        : reverseDecimalDigits.cpp
// Author      : Marius Popescu
// Assignment 3: Questoion 7
// Description : This program will display the decimal digits of an integer in reverse order
//============================================================================


#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>
using namespace std;

int reverse (int number, int m) ;

int main()
{
	int input;
	cout << "Enter number to reverse :";
	cin >> input;
	cout << reverse(input,0) << endl; //calling the function
	system("pause") ;
	return 0;
}
int reverse(int input,int m)
{
	//base case
	if(input==0)
		return m;
	m*=10;
	m+=input%10;
	//recursive function call
	return reverse(input/10,m);
}
