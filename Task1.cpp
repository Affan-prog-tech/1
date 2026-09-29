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
        current = current->next;

    current->next = newNode;
    newNode->prev = current;
}

void insertAtPosition(Node*& head, int value, int position)
{
    Node* newNode = new Node{value, NULL, NULL};

    if (position == 1)
    {
        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;

        head = newNode;
        return;
    }

    Node* current = head;

    for (int i = 1; i < position - 1 && current != NULL; i++)
        current = current->next;

    if (current == NULL)
    {
        cout << "Invalid position!" << endl;
        delete newNode;
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL)
        current->next->prev = newNode;

    current->next = newNode;
}

void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " <-> ";
        head = head->next;
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

    cout << "Original: ";
    display(head);

    insertAtPosition(head, 25, 3);

    cout << "Result: ";
    display(head);

    return 0;
}
