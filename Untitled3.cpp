#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

void insertAtBeginning(Node*& head, int value)
{
    Node* newNode = new Node{value, NULL, head};

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}

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

void display(Node* head)
{
    Node* current = head;

    while (current != NULL)
    {
        cout << current->data << " <-> ";
        current = current->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    Node* head = NULL;

    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtBeginning(head, 10);

    cout << "Doubly Linked List:\n";
    display(head);

    return 0;
}

