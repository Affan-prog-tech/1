#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insertAtBeginning(Node*& head, int value)
{
    Node* newNode = new Node{value, NULL};

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* last = head;

    while (last->next != head)
    {
        last = last->next;
    }

    newNode->next = head;
    last->next = newNode;
    head = newNode;
}

void display(Node* head)
{
    if (head == NULL)
    {
        cout << "List is empty.";
        return;
    }

    Node* current = head;

    do
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    while (current != head);

    cout << "(back to head)" << endl;
}

int main()
{
    Node* head = NULL;

    insertAtBeginning(head, 30);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 10);

    cout << "Circular Linked List:\n";
    display(head);

    return 0;
}
