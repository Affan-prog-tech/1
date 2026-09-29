#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* prev;
	Node* next;
};

int main()
{
	Node* head = NULL;
	Node* first = new Node;
	Node* second = new Node;
	Node* third = new Node;
	first->data = 10;
	second->data = 20;
	third->data = 30;
	first->prev = NULL;
	first->next = second;
	second->prev = first;
	second->next = third;
	third->prev = second;
	third->next = NULL;
	head = first;
	Node* current = head;
	cout << "Doubly Linked List:\n";
	while (current != NULL)
	{
	cout << current->data << " <-> ";
	current = current->next;
	}
	cout << "NULL" << endl;
	return 0;
}

