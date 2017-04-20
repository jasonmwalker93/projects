#include <iostream>
#include <string>
#include "intSLList.h"
using namespace std;

IntSLList::~IntSLList() 
{
	for (IntSLLNode *p; !isEmpty();) 
	{
		p = head->next;
		delete head;
		head = p;
	}
}
void IntSLList::addToHead(int el) 
{
	head = new IntSLLNode(el, head);
	if (tail == 0)
		tail = head;
}
void IntSLList::addToTail(int el) 
{
	if (tail != 0) 
	{										// if list not empty
		tail->next = new IntSLLNode(el);
		tail = tail->next;
	}
	else head = tail = new IntSLLNode(el);
}
int IntSLList::deleteFromHead() 
{
	int el = head->info;
	IntSLLNode *tmp = head;
	if (head == tail)						// if only one node in the list;
		head = tail = 0;
	else head = head->next;
	delete tmp;
	return el;
}
int IntSLList::deleteFromTail() 
{
	int el = tail->info;
	if (head == tail) 
	{										// if only one node in the list;
		delete head;
		head = tail = 0;
	}
	else 
	{										// if more than one node in the list,
		IntSLLNode *tmp;					// find the predecessor of tail;
		for (tmp = head; tmp->next != tail; tmp = tmp->next);
		delete tail;
		tail = tmp;							// the predecessor of tail becomes tail;
		tail->next = 0;
	}
	return el;
}
void IntSLList::deleteNode(int el) 
{
	if (head != 0)							// if nonempty list;
		if (head == tail && el == head->info) 
		{		// if only one
			delete head;					// node in the list;
			head = tail = 0;
		}
		else if (el == head->info) 
		{									// if more than one node in the list
			IntSLLNode *tmp = head;
			head = head->next;
			delete tmp;						// and old head is deleted;
		}
		else 
		{									// if more than one node in the list
			IntSLLNode *pred, *tmp;
			for (pred = head, tmp = head->next;			// and a nonhead node
				tmp != 0 && !(tmp->info == el);			// is deleted;
				pred = pred->next, tmp = tmp->next);
			if (tmp != 0) 
			{
				pred->next = tmp->next;
				if (tmp == tail)
					tail = pred;
				delete tmp;
			}
		}
}
bool IntSLList::isInList(int el) const 
{
	IntSLLNode *tmp;
	for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
	return tmp != 0;
}
void IntSLList::displayList()
{
	IntSLLNode *tmp = head;					// start tmp at beginning of list
	while (tmp != NULL)						// tmp will become null at end of list
	{
		cout << tmp->info << "\t";
		tmp = tmp->next;
	}
}
int IntSLList::listCount()
{
	IntSLLNode *tmp = head;					// start tmp at beginning of list
	int count = 0;
	while (tmp != NULL)						// tmp will become null at end of list
	{
		count++;
		tmp = tmp->next;
	}
	return count;
}
void IntSLList::multiply(int n)
{
	IntSLLNode *tmp = head;					// start tmp at beginning of list
	while (tmp != NULL)						// tmp will become null at end of list
	{
		tmp->info = tmp->info * n;
		tmp = tmp->next;
	}
}
int IntSLList::frequency(int n)
{
	IntSLLNode *tmp = head;					// start tmp at beginning of list
	int count = 0;
	if (head == tail)
		cout << "Error: empty list" << endl;
	while (tmp != NULL)						// tmp will become null at end of list
	{
		if (tmp->info == n)
			count++;
		tmp = tmp->next;
	}
	return count;
}
void IntSLList::deleteAll()
{
	if (head == tail)
		cout << "Error: empty list" << endl;
	for (int x = 0; x < listCount(); x++)
	{
		deleteFromTail();
		if (head == tail)
			head = tail = 0;
	}
}
void IntSLList::reverse()
{
	if (head == tail)
		cout << "Error: empty list" << endl;
	IntSLLNode *tmp = head, *prev = NULL, *aft = NULL;
	while (tmp != NULL)
	{
		aft = tmp->next;					//stores the address of the next node temporarily (it will overwritten in next line)
		tmp->next = prev;					//replaces the address of the next node with that of the previous node
		prev = tmp;							//sets previous to the address of the next node in the list
		tmp = aft;							//sets tmp to the address of the next node in the list
		head = prev;						//updates head to hold the address of the first node in the list
	}
}
void IntSLList::appendList(IntSLList& l2)
{
	tail->next = l2.head;
	tail = l2.tail;
	l2.head = l2.tail = 0;
}
void IntSLList::removeNode(int n)
{
	IntSLLNode *tmp = head, *prev;

	for (int i = 0; i < n - 2; i++)
		tmp = tmp->next;								//move pointer to n - 2

	prev = tmp;				
	tmp = tmp->next->next;								//sets tmp to address of n + 1
	prev->next = tmp;									//sets n - 1 node to n + 1 node
}
void IntSLList::removeNodes(int n, int x)				//smaller node number should be n, larger should be x
{
	if (n <= listCount() && x <= listCount())
	{
		for (int y = 0; y <= (x - n); y++)
			removeNode(n);								//calls removeNode function on appropriate nodes
	}
	else
		cout << "Error: parameters not within list specifications.";
}

int main()
{
		IntSLList list1, list2;
		int input, n, x;
		
		cout << "Enter number to push onto list (or -1 to quit): ";
		cin >> input;

		if (input != -1)
		{

		while (input != -1)
		{
			list1.addToTail(input);
			cout << "Enter number to push onto list (or -1 to quit): ";
			cin >> input;
		}
		
		cout << "List contents: ";
		list1.displayList();
		cout << "\nNumber of nodes in the list: " << list1.listCount() << endl;

		cout << "Enter a number in which to multiply all nodes by: ";
		cin >> input;

		list1.multiply(input);
		cout << "List contents: ";
		list1.displayList();

		cout << "\nEnter a number in which to find the frequency of in the list: ";
		cin >> input;
		cout << "Frequency: " << list1.frequency(input);

		cout << "\nEnter two numbers, a range, in which to delete all nodes in between (leave a space between the numbers): ";
		cin >> n >> x;
		while (n < 0 || x > list1.listCount())
		{
			cout << "The number or numbers you have entered are inappropriate. Please enter the numbers again: ";
			cin >> n >> x;
		}
		list1.removeNodes(n, x);
		cout << "List contents: ";
		list1.displayList();

		cout << "\nCreating a second list..." << endl;

		for (int z = 1; z <= 3; z++)
			list2.addToTail(z);

		cout << "2nd list contents: ";
		list2.displayList();

		cout << "\nAppending second list to the first..." << endl;
		list1.appendList(list2);
		cout << "List contents: ";
		list1.displayList();

		cout << "\nReversing list..." << endl;
		list1.reverse();
		cout << "List contents: ";
		list1.displayList();
		cout << endl;

		}


	system("pause");
	return 0;
}