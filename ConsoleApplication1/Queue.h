#include<iostream>
using namespace std;

class Node1

{
public:
	string customer_name;
	int cost;
	Node1* next;

	Node1(string nm,int cst)
	{
		customer_name = nm;
		cost = cst;
		next = NULL;

	}
};


Node1* front = NULL;
Node1* rear = NULL;



void enqueue(string name,int cst)

{
	Node1* ptr = new Node1(name,cst);
	ptr->customer_name = name;
	ptr->cost = cst;
	ptr->next = NULL;

	if (front == NULL) 
	{
		front = ptr;
		rear = ptr;
	}
	else 
	{
		rear->next = ptr;
		rear = ptr;
	}
}


void dequeue()

{
	if (front == NULL && rear == NULL)

		cout << "There are no Customers\n";

	else
	{
		if (front == rear) 
		
		{
			delete front;
			front = rear = NULL;
		}
		else 
		
		{
			Node1* temp = front;
			front = front->next;
			delete temp;
		}

	}

}


void display_queue()

{
	if ((front == NULL && rear == NULL))

		cout << "There are no Customers\n";

	else {
		Node1* ptr = front;
		while (ptr != NULL) 
		{
			cout << "\t" << ptr->customer_name << "\t, Cost = "<<ptr->cost<<"\t" << endl;
			ptr = ptr->next;
		}
	}
}

