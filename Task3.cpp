#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int id;
    string title;
    string artist;
    Node* prev;
    Node* next;
};

void addBeginning(Node*& head, Node*& tail, int id, string title, string artist)
{
    Node* newNode = new Node{id, title, artist, NULL, head};

    if (head != NULL)
        head->prev = newNode;
    else
        tail = newNode;

    head = newNode;
}

void addEnd(Node*& head, Node*& tail, int id, string title, string artist)
{
    Node* newNode = new Node{id, title, artist, tail, NULL};

    if (tail != NULL)
        tail->next = newNode;
    else
        head = newNode;

    tail = newNode;
}

void addPosition(Node*& head, Node*& tail, int id, string title, string artist, int position)
{
    if (position <= 1)
    {
        addBeginning(head, tail, id, title, artist);
        return;
    }

    Node* current = head;

    for (int i = 1; i < position - 1 && current != NULL; i++)
        current = current->next;

    if (current == NULL || current->next == NULL)
    {
        addEnd(head, tail, id, title, artist);
        return;
    }

    Node* newNode = new Node{id, title, artist, current, current->next};

    current->next->prev = newNode;
    current->next = newNode;
}

void deleteSong(Node*& head, Node*& tail, int id)
{
    Node* current = head;

    while (current != NULL && current->id != id)
        current = current->next;

    if (current == NULL)
    {
        cout << "Song not found!" << endl;
        return;
    }

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        head = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;
    else
        tail = current->prev;

    delete current;

    cout << "Song deleted successfully!" << endl;
}

void searchSong(Node* head, int id)
{
    Node* current = head;

    while (current != NULL)
    {
        if (current->id == id)
        {
            cout << "Song Found!" << endl;
            cout << "ID: " << current->id << endl;
            cout << "Title: " << current->title << endl;
            cout << "Artist: " << current->artist << endl;
            return;
        }

        current = current->next;
    }

    cout << "Song not found!" << endl;
}

void displayForward(Node* head)
{
    if (head == NULL)
    {
        cout << "Playlist is empty!" << endl;
        return;
    }

    Node* current = head;

    while (current != NULL)
    {
        cout << current->id << " | "
             << current->title << " | "
             << current->artist << endl;

        current = current->next;
    }
}

void displayBackward(Node* tail)
{
    if (tail == NULL)
    {
        cout << "Playlist is empty!" << endl;
        return;
    }

    Node* current = tail;

    while (current != NULL)
    {
        cout << current->id << " | "
             << current->title << " | "
             << current->artist << endl;

        current = current->prev;
    }
}

void countSongs(Node* head)
{
    int count = 0;
    Node* current = head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    cout << "Total Songs: " << count << endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int choice;

    do
    {
        cout << "\n===== MUSIC PLAYLIST =====" << endl;
        cout << "1. Add Song at Beginning" << endl;
        cout << "2. Add Song at End" << endl;
        cout << "3. Add Song at Position" << endl;
        cout << "4. Delete Song" << endl;
        cout << "5. Search Song" << endl;
        cout << "6. Display Playlist Forward" << endl;
        cout << "7. Display Playlist Backward" << endl;
        cout << "8. Count Songs" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int id, position;
        string title, artist;

        switch (choice)
        {
        case 1:
            cout << "Enter Song ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Song Title: ";
            getline(cin, title);

            cout << "Enter Artist: ";
            getline(cin, artist);

            addBeginning(head, tail, id, title, artist);
            break;

        case 2:
            cout << "Enter Song ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Song Title: ";
            getline(cin, title);

            cout << "Enter Artist: ";
            getline(cin, artist);

            addEnd(head, tail, id, title, artist);
            break;

        case 3:
            cout << "Enter Song ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Song Title: ";
            getline(cin, title);

            cout << "Enter Artist: ";
            getline(cin, artist);

            cout << "Enter Position: ";
            cin >> position;

            addPosition(head, tail, id, title, artist, position);
            break;

        case 4:
            cout << "Enter Song ID to delete: ";
            cin >> id;

            deleteSong(head, tail, id);
            break;

        case 5:
            cout << "Enter Song ID to search: ";
            cin >> id;

            searchSong(head, id);
            break;

        case 6:
            cout << "\nPlaylist Forward:" << endl;
            displayForward(head);
            break;

        case 7:
            cout << "\nPlaylist Backward:" << endl;
            displayBackward(tail);
            break;

        case 8:
            countSongs(head);
            break;

        case 9:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 9);

    return 0;
}
