#include <iostream>
#include <string>
#include "Queue.h"
#include "Stack.h"
using namespace std;

int search(int id);
int display();



class node

{
public:
	int ID;
	string Name;
	double Price;
	int Quantity;
	node* next;



	node(int _ID, string _Name, double _Price, int _Quantity) {
		ID = _ID;
		Name = _Name;
		Price = _Price;
		Quantity = _Quantity;
		next = NULL;
	}
};


node* head = NULL;
node* tail = NULL;

void Add_Food()

{

	system("cls");
	int id, quantity;
	double price;
	string name;
	

	cout << "Enter an ID of the food : ";
	cin >> id;
	cout << "Enter the name of the food : ";
	cin >> name;
	cout << "Enter the price of the food : ";
	cin >> price;
	cout << "Enter food quantity : ";
	cin >> quantity;

	node* newnode = new node(id, name, price, quantity);

	if (head == NULL)
	{
		newnode->next = head;
		head = tail = newnode;
	}
	else
	{
		tail->next = newnode;
		newnode->next = NULL;
		tail = newnode;
	}
	system("cls");
	cout << "\n \t" << name << " is added succsesfully!\n";

}



void delete_food()

{
	system("cls");
	display();
	int id;
	cout << "\nEnter the ID of the food that you want to delete: ";
	cin >> id;

	if (head == NULL)
	{
		cout << "List is empty!" << endl;

	}
	else
	{

		node* current = head;
		node* prev = NULL;

		if (current->ID == id)
		{
			head = current->next;
			delete current;
			cout << "Food item deleted successfully." << endl;
			return;
		}
		else {

			while (current != NULL && current->ID != id)
			{
				prev = current;
				current = current->next;
			}

			if (current == NULL)
			{
				cout << "\nFood item not found!\n";

			}
			else {
				prev->next = current->next;
				delete current;

				cout << "Food item deleted successfully" << endl;
			}
		}
	}
}


int display()

{
	system("cls");
	int c = 0;
	node* temp = head;


	cout << "\t\t\t ---<<<FOOD MENU>>>--- \n\n";
	cout << "ID\t\tFood name\t\tPrice\t\t\tQuantity\n";
	cout << "--------------------------------------------------------------------------------\n";
	while (temp != NULL)

	{
		cout << temp->ID << "\t\t" << temp->Name << "\t\t\t" << temp->Price << "\t\t\t" << temp->Quantity << "\n";
		temp = temp->next;
		c += 1;
	}

	cout << "\nTotal food items in our restaurent is : " << c << "\n\n";
	return c;
}

int search(int id)

{
	int count = 1;
	node* temp = head;
	while (temp != NULL)
	{
		if (temp->ID == id)
		{
			break;
		}
		else
		{
			count++;
			temp = temp->next;
		}
	}
	return count;
}

int table_cons = 31;

void buy()

{
	system("cls");
	display();
	string foods[20];
	int pay = 0, no, c = 0, price, id, i = 1;
	if (head == NULL)
	{
		cout << "\nSorry :( There is no foods right now !!!\n\n";
	}
	else
	{
		int popped_data = pop();
		table_cons = table_cons - 2;
		cout << "Remaining Tables : " << popped_data << endl << endl;
		cout << "Your table is : " << popped_data - table_cons << endl << endl;

		cout << "====================" << endl;
		cout << "   ||          ||" << endl;
		cout << "   ||          ||" << endl;
		cout << "   ||          ||" << endl;
		cout << "   ||          ||" << endl;
		cout << "   ||          ||" << endl;


		cout << "How many food items you want to buy?";
		cin >> no;
		int count = display();
		while (i <= no)
		{
			node* current = head;
			int quantity, choice;
		a:
			cout << "Enter id of food that you want to buy : ";
			int id, pos = 0;
			cin >> id;
			if (id == -1)
			{
				system("cls");
				return;
			}
			pos = search(id);
			if (pos <= count)
			{
				while (current->ID != id)
					current = current->next;
				cout << "How many food quantities you want ?";
				cin >> quantity;
				if (current->Quantity < quantity)
				{
					cout << "\n\n\t\t\t----The quantity you entered is not available----" << endl;
					cout << "\n\t\t\t----{press -1 for back to main menu}----" << endl;
					goto a;
				}
				foods[c] = current->Name;
				c++;

				pay = pay + (current->Price * quantity);
				current->Quantity = current->Quantity - quantity;
				i++;

			}
			else cout << "\n<<<This food is not available in our restaurant>>>\n\n";
		}
		string customer;
		cout << "\n\t\tEnter your name : ";
		cin >> customer;
		enqueue(customer, pay * 0.9);
		system("cls");
		cout << "\n\n\n\n\t\tyou have bought : ";

		for (int i = 0; i < no; i++)
		{
			cout << foods[i] << "    ";
		}

		price = pay * 0.9;
		cout << "\n\nOriginal price : " << pay << endl;;
		cout << "\nwith 10% discount : " << price << endl << "\nThank you! Enjoy your foods! \n\n";

	}

}

void admin()

{
	system("cls");
	int choice;

	do {
		cout << endl;
		cout << "\t\t***************************************" << endl;
		cout << "\t\t*          Administrator Panel        *" << endl;
		cout << "\t\t***************************************" << endl;
		cout << endl;
		cout << "\t\t Enter 1 to add new food item" << endl;
		cout << "\t\t Enter 2 to display all foods in the restaurant" << endl;
		cout << "\t\t Enter 3 to delete a particular food item" << endl;
		cout << "\t\t Enter 4 to customers list" << endl;
		cout << "\t\t Enter 5 to remove the first customer from the list" << endl;
		cout << "\t\t Enter 0 Main Menu" << endl;

		cout << "\nEnter your choice>>>";
		cin >> choice;
		switch (choice)

		{
		case 1:
			Add_Food();
			break;
		case 2:
			system("cls");
			display();
			break;
		case 3:
			delete_food();
			break;
		case 4:
			system("cls");
			cout << "========Customers Names List=======" << endl << endl;
			display_queue();
			break;
		case 5:
			system("cls");
			cout << "=======Customers Names List========" << endl << endl;;
			dequeue();
			display_queue();
			break;

		default:system("cls");

		}

	} while (choice != 0);

}

int main()

{

	for (int i = 1; i < 31; i++)
	{
		push(i);
	}

	cout << "\t\t------------------------------------------" << endl;
	cout << "\t\t|       Restaurent Manegement System     |" << endl;
	cout << "\t\t------------------------------------------" << endl;

	int choice = 0;
	while (choice != 3)
	{

		cout << "\n\t\t|-----<Main Menu>-----|";
		cout << "\n\n";
		cout << "\t\t 1)Administration of the Restaurent\n";
		cout << "\t\t 2)Customer           \n";
		cout << "\t\t 3)Exit      \n";

		cout << "\nEnter your choice>>>";
		cin >> choice;
		switch (choice)

		{
		case 1:
			admin();
			break;
		case 2:
			cout << endl << endl;
			buy();
			break;
		case 3:
			cout << "\n\n\t\tThank you! Have a nice day!";
			break;
		}
	}

	return 0;

}