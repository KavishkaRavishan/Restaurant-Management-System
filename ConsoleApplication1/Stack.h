#include<iostream>
using namespace std;

class Node

{
public:
	int data;
	Node* next;

	Node(int val)
	{
		data = val;
		next = NULL;
	}
};



Node* top;


void push(int data)

{

	Node* temp = new Node(data);
	temp->data = data;
	temp->next = top;
	top = temp;
}


int pop()

{
	Node* temp;
	int popped;
	if (top == NULL)

	{
		cout << "\nstack underflow!" << endl;
		exit(1);
	}
	else

	{
		temp = top;
		popped = temp->data;
		top = top->next;
		delete temp;

	}

	return popped;

}


