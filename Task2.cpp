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
        current = current->next;

    current->next = newNode;
    newNode->next = head;
}

void deleteNode(Node*& head, int value)
{
    if (head == NULL)
        return;

    Node* current = head;
    Node* previous = NULL;

    do
    {
        if (current->data == value)
        {
            if (current == head)
            {
                Node* last = head;

                while (last->next != head)
                    last = last->next;

                if (head->next == head)
                {
                    delete head;
                    head = NULL;
                    return;
                }

                head = head->next;
                last->next = head;
                delete current;
                return;
            }

            previous->next = current->next;
            delete current;
            return;
        }

        previous = current;
        current = current->next;

    } while (current != head);

    cout << "Value not found!" << endl;
}

void display(Node* head)
{
    if (head == NULL)
        return;

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
    insertAtEnd(head, 50);

    cout << "Original: ";
    display(head);

    deleteNode(head, 30);

    cout << "Result: ";
    display(head);

    return 0;
}
