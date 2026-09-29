#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int value)
{
    Node* newNode = new Node{value, NULL};

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* current = head;

    while (current->next != head)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = head;
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
    } while (current != head);

    cout << "(back to head)" << endl;
}

int main()
{
    Node* head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Circular Linked List:\n";
    display(head);

    return 0;
}
