//Marius Popescu
//CS300
//Assignment 3, Question 1 and Question 2
// 05.21.2017

#include <iostream>
#include "LListFindNthFMidle.h"
using namespace std;

int main(){

	LinkedList<int> mylist;
	cout << "Enter a number:";
	int x;
	cin >> x;
	while (x != -99){
		mylist.insert_last(x);
		cout << "Enter a number:";
		cin >> x;
	}
	cout << mylist << endl;
	cout << "size:" << mylist.length() << endl;

	//Question 1 - return the nth element from end
	cout << "Enter desired element order number from the end to search for it: \n";
	cin >> x;
	mylist.findNth(x);

	//Question 2 - call the middle function 
	mylist.middle();    

	mylist.destroy_list();
	cout << mylist;
	system("pause");
	return 0;


}
