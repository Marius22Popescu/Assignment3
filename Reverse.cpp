#include <iostream>
using namespace std;


template <class T>
struct node{
	int data;
	node* next;
};

template <class T>
class LinkedList{
protected:
	node<T> *head, *last;
	int count;
public:
	LinkedList();
	bool is_empty();
	int length();
	void insert_first(T&);
	void insert_last(T&);
	template <class U>
	friend ostream& operator<< (ostream& os, LinkedList<U>& list);
	node<T>* search(T&);
	node<T>* middle();
	node<T>* findNth(T&);
	void delete_node(T&);
	void reverse();
	void reverselist(node<T>* p);

	T back();
	T front();
	void destroy_list();
	virtual ~LinkedList();
private:
	void copy_list(LinkedList<T> otherlist);

};

//initializing the list: constructor
template <class T>
LinkedList<T>::LinkedList(){
	cout << "Initializing list..." << endl;
	head = NULL;
	last = NULL;
	count = 0;

}
//check if list is empty
template <class T>
bool LinkedList<T>::is_empty(){
	return head == NULL;
}

//get the number of nodes in the list
template <class T>
int LinkedList<T>::length(){
	return count;
}

//insert a new lelement to the front
template <class T>
void LinkedList<T>::insert_first(T& item){
	node<T>* current = new node<T>;
	current->data = item;
	current->next = NULL;
	if (head != NULL){
		current->next = head;
		head = current;
	}
	else{
		head = last = current;
	}
	count++;
}

//insert a new item at the end of the list
template <class T>
void LinkedList<T>::insert_last(T& item){
	node<T>* current = new node<T>;
	current->data = item;
	current->next = NULL;
	if (head != NULL){
		last->next = current;
		last = current;

	}
	else{
		head = last = current;
	}
	count++;
}

template <class T>
ostream& operator<< (ostream& os, LinkedList<T>& list){
	node<T>* temp = list.head;
	while (temp != NULL){
		os << temp->data << " ";
		temp = temp->next;
	}
	return os;
}

template <class T>
node<T>* LinkedList<T>::search(T& item){
	node<T>* temp = head;
	while (head != NULL && temp->data != item){
		temp = temp->next;
	}
	cout << temp->data << endl;

	return temp;
}

//Question 1 - This function will return the nth element from end in a linked list and will traverse the linked list only once.
template <class T>
node<T>* LinkedList<T>::findNth(T& item){
	node<T>* temp = head;
	int i = 0;
	int y = item;
	y = count - y;
	while (i != y){
		temp = temp->next;
		i++;
	}
	cout << item << "th element: " << temp->data << endl;

	return temp;
}

//Question 2 - This function will find the middle element from a linked list
template <class T>
node<T>* LinkedList<T>::middle(){
	node<T>* temp = head;
	int y = 0;
	int i = 0;
	y = count / 2;
	while (i != y)
	{
		temp = temp->next;
		i++;
	}
	cout << "Middle element: " << temp->data << endl;

	return temp;
}

template <class T>
void LinkedList<T>::delete_node(T& item){
	node<T> *p, *q;
	if (head == NULL)
		cout << "List is empty..." << endl;
	else
		if (head->data == item){
			p = head;
			head = head->next;
			delete p;
			count--;
			if (head == NULL)
				last = NULL;
		}
		else{
			p = head;
			q = head->next;
			while (q != NULL && q->data != item){
				p = q;
				q = q->next;
			}
			if (q == NULL)
				cout << "item is not found";
			else{
				p->next = q->next;
				if (q->next == NULL)
					last = p;
				delete q;
				count--;

			}

		}

}
template <class T>
T LinkedList<T>::back(){
	assert(last != NULL);
	return last->data;
}

template <class T>
T LinkedList<T>::front(){
	assert(head != NULL);
	return head->data;
}
template <class T>
void LinkedList<T>::destroy_list(){
	node<T>* p;
	while (head != NULL){
		p = head;
		head = head->next;
		delete p;
	}
	last = NULL;
	count = 0;
}

//destructor
template <class T>
LinkedList<T>::~LinkedList(){
	cout << "List is destroyed..." << endl;
	destroy_list();
}

template <class T>
void LinkedList<T>::reverselist(node<T>* p)
{
	if (!p)
		return;
	node<T>* rest = head->next;
	if (rest == NULL)
		return;
	reverselist(rest);
	p->next->next = p;
	p->next = NULL;
	p = rest;

}

template <class T>
void LinkedList<T>::reverse()
{
	
	node<T>* s = head;
	reverselist( s);
}

int main(){

	LinkedList<int> mylist;
	cout << "Enter a number or -99 to stop:";
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

	//Question 6 - call the reverse function

	mylist.reverse();
	cout << mylist << endl;



	mylist.destroy_list();
	cout << mylist;
	system("pause");    //uncomment if you need to stop the screan !!!
	return 0;


}
