#include <iostream>
#include <string>
#include <windows.h>
#include <stdexcept>
using namespace std;

class Node
{
public:
    int data;
    Node *previous;
    Node *next;

    Node(int data = 0)
    {
        this->data = data;
        this->previous = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        delete previous;
        delete next;
    }
};

int getSize(Node *&head)
{
    int size = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

void print(Node *&head)
{
    if (head == NULL)
    {
        cout << "Currently List is Empty." << endl
             << endl;
        return;
    }
    Node *temp = head;
    cout << "===================================\nList: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "===================================\n";
}

void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        system("CLS");
        return;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->previous = temp;
        head = temp;
        system("CLS");
    }
}

void insertAtTail(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        system("CLS");
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *nodeToInsert = new Node(data);
    temp->next = nodeToInsert;
    nodeToInsert->previous = temp;
    system("CLS");
}

void insertAtPosition(Node *&head, int position, int data)
{
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(head, data);
        return;
    }

    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->previous = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->previous = temp;
    system("CLS");
}

void changeHead(Node *&head, int position)
{
    if (head == NULL)
    {
        cout << "\n\tList is Empty.\n";
        return;
    }

    if (position == 1)
    {
        cout << "List Remains Same.\n"
             << endl;
        return;
    }

    Node *temp = head;
    int count = 1;

    while (temp != NULL && count < position)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        cout << "Invalid position. List remains same.\n";
        return;
    }

    temp->previous->next = NULL;
    temp->previous = NULL;

    if (temp->next == NULL)
    {
        temp->next = head;
    }
    else
    {
        Node *last = temp;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = head;
    }
    head = temp;
}

int main()
{
    Node *node;
    Node *head = NULL;

    string input;
    int num, index, choice, run = 0;
    cout << "=====================================" << endl
         << "         Doubly Linked List " << endl
         << "=====================================" << endl;
    while (true)
    {
        cout << "  Choose an operation:" << endl
             << "    1. Add to the head" << endl
             << "    2. Add to the tail" << endl
             << "    3. Add at a specific location" << endl
             << "    4. Change Head" << endl
             << "    5. Check Current State of List" << endl
             << "    6. Quit" << endl;

        while (true)
        {
            cout << "\nEnter Choice: ";
            try
            {
                getline(cin, input);
                choice = stoi(input);
                if (choice < 1 || choice > 6)
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "Invalid Choice Range." << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else
                {
                    break;
                }
            }
            catch (const invalid_argument &e)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 12);
                cout << "Invalid input. Please enter an integer." << endl;
                SetConsoleTextAttribute(hConsole, 7);
            }
        }
        cout << endl;

        switch (choice)
        {
        case 1:
            while (true)
            {
                cout << "Enter the number to add to head: ";
                try
                {
                    getline(cin, input);
                    num = stoi(input);
                    break;
                }
                catch (const invalid_argument &e)
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "Invalid input. Please enter an integer." << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
            }
            insertAtHead(head, num);
            print(head);
            break;

        case 2:
            while (true)
            {
                cout << "Enter the number to add to the tail: ";
                try
                {
                    getline(cin, input);
                    num = stoi(input);
                    break;
                }
                catch (const invalid_argument &e)
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "Invalid input. Please enter an integer." << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
            }
            insertAtTail(head, num);
            print(head);
            break;

        case 3:
            while (true)
            {
                cout << "Enter the number to add: ";
                try
                {
                    getline(cin, input);
                    num = stoi(input);
                    break;
                }
                catch (const invalid_argument &e)
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "Invalid input. Please enter an integer." << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
            }
            if (getSize(head) == 0)
            {
                index = 1;
                run++;
            }
            else
            {
                while (true)
                {

                    cout << "Enter the index from 1 to " << getSize(head) + 1 << ": ";
                    try
                    {
                        getline(cin, input);
                        index = stoi(input);
                        if (index < 1 || index > getSize(head) + 1)
                        {
                            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                            SetConsoleTextAttribute(hConsole, 12);
                            cout << "Invalid Index Range." << endl;
                            SetConsoleTextAttribute(hConsole, 7);
                        }
                        else
                        {
                            break;
                        }
                    }
                    catch (const invalid_argument &e)
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 12);
                        cout << "Invalid input. Please enter an integer." << endl;
                        SetConsoleTextAttribute(hConsole, 7);
                    }
                }
            }
            insertAtPosition(head, index, num);
            if (run == 1)
            {
                cout << "List is Empty. So value placed at 1st." << endl;
                run = 0;
            }
            print(head);
            break;
        case 4:
            if (getSize(head) == 0)
            {
                system("CLS");
                cout << "\n\tList is Empty.\n"
                     << endl;
            }
            else
            {
                while (true)
                {

                    cout << "Enter the index from 1 to " << getSize(head) << ": ";
                    try
                    {
                        getline(cin, input);
                        index = stoi(input);
                        if (index < 1 || index > getSize(head))
                        {
                            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                            SetConsoleTextAttribute(hConsole, 12);
                            cout << "Invalid Index Range." << endl;
                            SetConsoleTextAttribute(hConsole, 7);
                        }
                        else
                        {
                            break;
                        }
                    }
                    catch (const invalid_argument &e)
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 12);
                        cout << "Invalid input. Please enter an integer." << endl;
                        SetConsoleTextAttribute(hConsole, 7);
                    }
                }
                system("CLS");
                cout << "Position: " << index << endl
                     << endl;
                cout << "Before:" << endl;
                print(head);
                cout << endl;
                changeHead(head, index);
                cout << "After:" << endl;
                print(head);
            }
            break;

        case 5:
            system("CLS");
            cout << "Number of elements in List: " << getSize(head) << endl;
            print(head);
            break;

        case 6:
            cout << "\n\t\tGood Bye :)\n\n";
            exit(0);

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    delete node;
    delete head;

    return 0;
}