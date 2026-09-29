#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int id;
    string name;
    float marks;
    Student* next;
};

void insertStudent(Student*& head, int id, string name, float marks)
{
    Student* newStudent =
        new Student{id, name, marks, NULL};

    if (head == NULL)
    {
        head = newStudent;
        return;
    }

    Student* current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newStudent;
}

void displayStudents(Student* head)
{
    Student* current = head;

    cout << "\nStudent Records\n";
    cout << "-----------------------------\n";

    while (current != NULL)
    {
        cout << "ID: " << current->id << endl;
        cout << "Name: " << current->name << endl;
        cout << "Marks: " << current->marks << endl;
        cout << "-----------------------------\n";

        current = current->next;
    }
}

int main()
{
    Student* head = NULL;

    insertStudent(head, 101, "Ali", 85.5);
    insertStudent(head, 102, "Sara", 91.0);
    insertStudent(head, 103, "Ahmed", 78.5);

    displayStudents(head);

    return 0;
}
