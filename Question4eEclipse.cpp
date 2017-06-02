//============================================================================
// Name        : Question4eEclipse.cpp
// Author      : Marius Popescu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Stack.h"
#include <string>
#include <cstring>
using namespace std;

string add(string a, string b);

int main()
{
	add("1876543217", "0000008292");
}

string add(string a, string b)
{
	Stack<int> s1(25);
	Stack<int> s2(25);
	Stack<int> s3(26);
	int nr = 0;
	for (int i = 0; i <= a.length(); i++){
		nr = a[i];
		s1.push(nr);
	}
	for (int i = 0; i <= b.length(); i++){
			nr = b[i];
			s2.push(nr);
	}
/**
	if (a.length()>b.length()){
		int diff;
		diff = a.length()-b.length();
		for (int i = 0; i < diff; i++){
			int zero = 0;
			s2.push(zero);
		}
	}***/

	char x, y;
	int i, j, k;
	s1.pop();
	s2.pop();
	while (!s1.isEmpty() && !s2.isEmpty()){
	x = s1.pop();
	y = s2.pop();
	i = x - '0';  //converting from char to integer
	j = y - '0';  //converting from char to integer
	k = i + j;
	cout << " k is: " << k <<endl;
	if (k<10)
	s3.push(k);
	else {
		k = k%10;
		s3.push(k);
	}
	}
	while(!s3.isEmpty()){
		k = s3.pop();
		cout << "k the sum is"<< k << endl;
	}


}
