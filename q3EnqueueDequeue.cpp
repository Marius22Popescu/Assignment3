#include <iostream>
#include "QueueStack.h"

using namespace std;



int main()
{
	int nr = 0;
	QueueStack<int> MyQueue;
	while (nr != -99){
		cout << "enter items: -99 to exit" << endl;
		cin >> nr;
		MyQueue.enqueue(nr);
	}
}
