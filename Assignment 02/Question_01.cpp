#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
using namespace std;

class Node
{
    string name;
    string address;
    string phNumber;
    Node *next;

public:
    Node(string name = "", string address = "", string phNumber = 0)
    {
        this->name = name;
        this->address = address;
        this->phNumber = phNumber;
        next = NULL;
    }

    void insert(Node *&head, string name, string address, string phNumber)
    {
        Node *nodeToInsert = new Node(name, address, phNumber);

        if (head == NULL || name < head->name)
        {
            nodeToInsert->next = head;
            head = nodeToInsert;
            cout << "\n\tAddress Added.\n"
                 << endl;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL && name > temp->next->name)
        {
            temp = temp->next;
        }

        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
        cout << "\n\tAddress Added.\n"
             << endl;
    }

    Node *search(Node *&head, string name)
    {
        if (head == NULL)
        {
            cout << "\tAddress Book is Empty.\n"
                 << endl;
            return NULL;
        }
        Node *temp = head;
        int chala = 0;
        while (temp != NULL)
        {
            if (temp->name == name)
            {
                cout << "Search Result: " << endl;
                cout << "\tName: " << temp->name << endl
                     << "\tAddress: " << temp->address << endl
                     << "\tPhone Number: " << temp->phNumber << endl;
                chala++;
            }
            temp = temp->next;
        }
        cout << endl;
        if (chala == 0)
        {
            cout << "\n\tAddress Not Found.\n\n";
        }
    }

    void display(Node *&head)
    {
        if (head == NULL)
        {
            cout << "\n\tAddress Book is Empty." << endl;
            return;
        }
        cout << "                   Address Book " << endl;
        cout << "=======================================================" << endl;
        cout << " " << setw(20) << left << "Name" << setw(20) << left << "Address" << setw(12) << left << "Phone Number" << endl;
        cout << "=======================================================" << endl;
        Node *temp = head;
        while (temp != NULL)
        {
            cout << " " << setw(20) << left << temp->name << setw(20) << left << temp->address << temp->phNumber << endl;
            temp = temp->next;
        }
    }

    ~Node()
    {
        delete next;
    }
};

int main()
{
    Node *node;
    Node *head = NULL;
    string input, name, address, phNumber;
    int choice;
    cout << "==================================" << endl
         << "          Address Book " << endl
         << "==================================" << endl;
    while (true)
    {
        cout << " Choose an operation" << endl
             << "    1. Add New Address" << endl
             << "    2. Search Address" << endl
             << "    3. Display Address Book" << endl
             << "    4. Exit" << endl;

        while (true)
        {
            cout << "\nEnter Choice: ";
            try
            {
                getline(cin, input);
                choice = stoi(input);
                if (choice < 1 || choice > 4)
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
                cout << "Enter Name: ";
                try
                {
                    getline(cin, name);
                    for (char &ch : name)
                    {
                        ch = toupper(ch);
                    }
                    if (name.length() > 20)
                    {
                        throw -1;
                    }
                    break;
                }
                catch (int e)
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "character for Name Must be Less then 20" << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
            }

            while (true)
            {
                cout << "Enter Address: ";
                try
                {
                    getline(cin, address);
                    if (address.length() > 20)
                    {
                        throw -1;
                    }
                    break;
                }
                catch (int e)
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "character for Address Must be Less then 20" << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
            }

            while (true)
            {
                cout << "Enter Phone Number: ";
                try
                {
                    getline(cin, phNumber);
                    if ((phNumber[0] != '0' || phNumber[1] != '3' || phNumber.length() != 11) && (phNumber[0] != '9' || phNumber[1] != '2' || phNumber.length() != 12))
                    {
                        throw -1;
                    }

                    break;
                }
                catch (int e)
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "Phone Number Format.\n03XXXXXXXXX\n92XXXXXXXXXX" << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
            }
            system("CLS");
            node->insert(head, name, address, phNumber);
            break;

        case 2:
            if (head == NULL)
            {
                system("CLS");
                cout << "\n\tAddress Book is Empty.\n"
                     << endl;
                break;
            }
            while (true)
            {
                cout << "Enter Name to sreach: ";
                try
                {
                    getline(cin, name);
                    for (char &ch : name)
                    {
                        ch = toupper(ch);
                    }
                    if (name.length() > 20)
                    {
                        throw -1;
                    }
                    break;
                }
                catch (int e)
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "character for Name Must be Less then 20" << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
            }
            system("CLS");
            node->search(head, name);
            break;
        case 3:
            system("CLS");
            node->display(head);
            cout << endl;
            break;

        case 4:
            cout << "\n\n\t\t\tGood Bye :)\n\n\n"
                 << endl;
            exit(0);

        default:
            cout << "Wrong Choice." << endl;
            break;
        }
    }

    delete node;
    return 0;
}
