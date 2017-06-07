//============================================================================
// Name        : q3EnqueueDequeue.cpp
// Author      : Marius Popescu
// Description : This program will perform the enqueue and dequeue functios with stack
//============================================================================

#include <iostream>
#include "QueueStack.h"

using namespace std;



int main()
{
	int nr = 0;
	int count = 0;
	QueueStack<int> MyQueue;              //create a queue
	cout << "enter items: -99 to exit" << endl;    //prompting the user for numbers to enqueue
	while (nr != -99){

		cin >> nr;
		MyQueue.enqueue(nr);                 //enqueue the numbers
		count ++;
	}
	for (int i = 1; i < count; i++){                //dequeue all queue
		nr = MyQueue.dequeue();
		cout << "Queue popped: " << nr <<endl;
	}

}
