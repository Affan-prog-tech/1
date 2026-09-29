#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* prev;
	Node* next;
};

void insertAtEnd(Node*& head, int value)
{
	Node* newNode = new Node{value, NULL, NULL};
	
if (head == NULL)
{
	head = newNode;
	return;
}

	Node* current = head;
	
while (current->next != NULL)
{
	current = current->next;
}
	current->next = newNode;
	newNode->prev = current;
}
void displayForward(Node* head)
{
	Node* current = head;
	
while (current != NULL)
{
	cout << current->data << " <-> ";
	current = current->next;
}
	cout << "NULL" << endl;
}

void displayBackward(Node* head)
{
	if (head == NULL)
	return;

	Node* current = head;
	
	while (current->next != NULL)
{
	current = current->next;
}

while (current != NULL)
{
	cout << current->data << " <-> ";
	current = current->prev;
}
	cout << "NULL" << endl;
}

int main()
{
	Node* head = NULL;
	insertAtEnd(head, 10);
	insertAtEnd(head, 20);
	insertAtEnd(head, 30);
	insertAtEnd(head, 40);
	cout << "Forward Traversal:\n";
	displayForward(head);
	cout << "\nBackward Traversal:\n";
	displayBackward(head);
	return 0;
}
