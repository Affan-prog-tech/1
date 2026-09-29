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

void deleteNode(Node*& head, int value)
{
    Node* current = head;

    while (current != NULL && current->data != value)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "Element not found." << endl;
        return;
    }

    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    else
    {
        head = current->next;
    }

    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }

    delete current;
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

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Before deletion:\n";
    display(head);

    deleteNode(head, 30);

    cout << "\nAfter deleting 30:\n";
    display(head);

    return 0;
}

