#include <iostream>
#include <windows.h>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Node
{
    int data;

public:
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    int getData()
    {
        return data;
    }

    ~Node()
    {
        Node *current = next;
        while (current != NULL)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
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
        cout << "=====================================\n List: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        cout << "=====================================\n";
    }

    void insertAtTail(Node *&head, int data)
    {
        if (head == NULL)
        {
            Node *temp = new Node(data);
            head = temp;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        Node *nodeToInsert = new Node(data);
        temp->next = nodeToInsert;
    }
    
    bool search(vector<int> &vec, int search)
    {
        for (int index : vec)
        {
            if (index == search)
            {
                return true;
            }
        }
        return false;
    }

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

    void swapNodes(Node *&head, int phala, int dusra)
    {
        Node *phalaPrevious = NULL;
        Node *phalaCurrent = head;
        for (int i = 1; i < phala && phalaCurrent->next != NULL; ++i)
        {
            phalaPrevious = phalaCurrent;
            phalaCurrent = phalaCurrent->next;
        }

        Node *dusrayPrevious = NULL;
        Node *dusrayCurrent = head;
        for (int i = 1; i < dusra && dusrayCurrent->next != NULL; ++i)
        {
            dusrayPrevious = dusrayCurrent;
            dusrayCurrent = dusrayCurrent->next;
        }

        if (phalaPrevious != NULL)
        {
            phalaPrevious->next = dusrayCurrent;
        }
        else
        {
            head = dusrayCurrent;
        }

        dusrayPrevious->next = phalaCurrent;

        Node *temp = phalaCurrent->next;
        phalaCurrent->next = dusrayCurrent->next;
        dusrayCurrent->next = temp;
    }

    void sort(Node *&head, vector<int> &indices)
    {
        int n = indices.size();

        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                if (getDataFromIndex(head, indices[j]) < getDataFromIndex(head, indices[j + 1]))
                {
                    swapNodes(head, indices[j], indices[j + 1]);
                }
            }
        }
    }

    int getDataFromIndex(Node *&head, int index)
    {
        if (index == 1)
        {
            return head->data;
        }

        Node *temp = head;

        int count = 1;
        while (count < index)
        {
            temp = temp->next;
            count++;
        }

        return temp->data;
    }
};

int main()
{
    Node *node = NULL;
    Node *head = NULL;

    string input;
    int data = 0, count = 1;

    cout << "Enter numbers to insert in list." << endl
         << "Enter \"-1\" to stop getting Input." << endl
         << endl;

    while (true)
    {
        cout << "  " << count << ". Enter a number: ";
        try
        {
            getline(cin, input);
            data = stoi(input);
            if (data == -1)
                break;
            node->insertAtTail(head, data);
            count++;
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

    cout << "UnSorted Linked List:" << endl;
    node->print(head);
    cout << endl;

    int index;
    vector<int> vec;
    int i = 0;
    int kitnay_change_karnay_hai = 0;
    while (true)
    {
        cout << "Enter the index from 1 to " << node->getSize(head) << ": ";
        try
        {
            getline(cin, input);
            index = stoi(input);

            if (index == -1)
            {
                break;
            }
            if (index < 1 || index > node->getSize(head))
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 12);
                cout << "Invalid Index Range." << endl;
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if (node->search(vec, index))
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 12);
                cout << "Duplicate index!\nPlease enter different index.\n";
                SetConsoleTextAttribute(hConsole, 7);
            }
            else
            {
                vec.push_back(index);
                kitnay_change_karnay_hai++;
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

    // cout << "before: ";
    // for (int i : vec)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    sort(vec.begin(), vec.end());

    // cout << "after: ";
    // for (int i : vec)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    node->sort(head, vec);

    cout << "Sorted List: " << endl;
    node->print(head);

    return 0;
}