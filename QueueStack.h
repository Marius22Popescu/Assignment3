//============================================================================
// Name        : q3EnqueueDequeue.cpp
// Author      : Marius Popescu
// Description : This program will perform the enqueue and dequeue functios with stack
//============================================================================

#include <iostream>
#include "Stack.h"
using namespace std;

#ifndef QUEUE_STACK_H_
#define QUEUE_STACK_H_

template <class T>
class QueueStack{

Stack<T> s1;
Stack<T> s2;
public:

void enqueue(T& item);
T dequeue();
};


template <class T>
void QueueStack<T>::enqueue(T& item){
	//write your code here
	s1.push(item);    //I use the function push from the stack in order to enqueue the items
}
template <class T>
T QueueStack<T>::dequeue(){
	//write your code here
	int x;
	x = s1.pop();    //First we will pop the items from the s1 and push there in s2 in order to reverse the elements from the stack
	s2.push(x);
	s2.pop();		 // Pop the elements from s2 in order to dequeue

}

#endif

