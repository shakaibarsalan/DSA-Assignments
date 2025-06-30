/*
    Name: Muhammad Shakaib Arsalan
    Student ID: F2022266626
    Section:  V16

    Submitted To: Sir Hafiz Ahsan Arshad
*/
#include <iostream>
#include <string>
#include <stdexcept>
#include <windows.h>
using namespace std;

class DynamicArray
{
private:
    int *arr;
    int size;
    int capacity;

public:
    DynamicArray(int capacity = 0)
    {
        this->capacity = capacity;
        size = 0;
        arr = new int[capacity];
    }

    int getSize()
    {
        return size;
    }

    int getCapacity()
    {
        return capacity;
    }

    void insertAtHead(int data)
    {
        if (size == capacity)
        {
            int *temp = new int[++capacity];

            for (int i = 0; i < size; i++)
            {
                temp[i + 1] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
        arr[0] = data;
        size++;
        system("CLS");
        display(0, 0);
        cout << endl;
    }

    void insertAtTail(int data)
    {
        if (size == capacity)
        {
            int *temp = new int[++capacity];

            for (int i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
        arr[size] = data;
        size++;
        system("CLS");
        display(size - 1, size - 1);
        cout << endl;
    }

    void insertAtPosition(int position, int data)
    {
        if (position < 0 || position > size)
        {
            cout << "Invalid Position." << endl;
            return;
        }

        if (size == capacity)
        {
            int *temp = new int[++capacity];

            for (int i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }

        for (int i = size; i > position; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[position] = data;
        size++;
        system("CLS");
        display(position, position);
        cout << endl;
    }

    void deleteFromHead()
    {
        if (size == 0)
        {
            cout << "\tArray is Empty." << endl;
            return;
        }

        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "\tDone Deletion." << endl;
    }

    void deleteFromTail()
    {
        if (size == 0)
        {
            cout << "\tArray is Empty." << endl;
            return;
        }
        size--;
        cout << "\tDone Deletion." << endl;
    }

    void deleteFromPosition(int position)
    {
        if (position < 0 || position > size - 1)
        {
            cout << "Invalid Position." << endl;
            return;
        }

        if (size == 0)
        {
            cout << "\n\tArray is Empty." << endl;
            return;
        }

        for (int i = position; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "\n\tDone Deletion." << endl;
    }

    void increaseSize(int newSize)
    {
        if (newSize < size)
        {
            cout << "Invalid Size." << endl;
            return;
        }
        else
        {
            cout << "\n\tSize Increased" << endl;
        }
        capacity = newSize - 1;
    }

    void display(int start = 0, int end = 0)
    {
        cout << "=====================================\n";
        cout << "Array: ";
        for (int i = 0; i < size; i++)
        {
            if (i >= start && i <= end)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 10);
                cout << arr[i] << " ";
                SetConsoleTextAttribute(hConsole, 7);
            }
            else
                cout << arr[i] << " ";
        }
        cout << endl;
        cout << "=====================================\n";
    }

    ~DynamicArray()
    {
        delete[] arr;
    }
};

int main()
{
    string input;
    int num, choice, index;
    while (true)
    {
        cout << "Enter the initial size of the array: ";
        try
        {
            getline(cin, input);
            num = stoi(input);
            if (num >= 0)
            {
                break;
            }
            else
            {

                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 12);
                cout << "Size of Array Must be a Positive Number." << endl;
                SetConsoleTextAttribute(hConsole, 7);
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

    DynamicArray *d = new DynamicArray(num);

    int *arr = new int[num];

    if (num > 0)
    {

        cout << "  ==== Initialize Array ====\n"
             << endl;
        for (int i = 0; i < num; i++)
        {
            while (true)
            {
                cout << "  arr[" << i << "]: ";
                try
                {
                    getline(cin, input);
                    arr[i] = stoi(input);
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
        }

        for (int i = 0; i < num; i++)
        {
            d->insertAtTail(arr[i]);
        }
    }

    while (true)
    {
        cout << "  Choose an operation:" << endl;
        cout << "    1. Add to the head" << endl;
        cout << "    2. Add to the tail" << endl;
        cout << "    3. Add at a specific location" << endl;
        cout << "    4. Delete from head" << endl;
        cout << "    5. Delete from tail" << endl;
        cout << "    6. Delete from a specific location" << endl;
        cout << "    7. Check Current State of array" << endl;
        cout << "    8. Increase Size of Array" << endl;
        cout << "    9. Quit" << endl;

        while (true)
        {
            cout << "Enter Choice: ";
            try
            {
                getline(cin, input);
                choice = stoi(input);
                if (choice < 1 || choice > 9)
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
            d->insertAtHead(num);
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
            d->insertAtTail(num);
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
            while (true)
            {
                cout << "Enter the index from 0 to " << d->getSize() << ": ";
                try
                {
                    getline(cin, input);
                    index = stoi(input);
                    if (index < 0 || index > d->getSize() )
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
            d->insertAtPosition(index, num);
            break;

        case 4:
            d->deleteFromHead();
            Sleep(1500);
            system("CLS");
            d->display();
            break;

        case 5:
            d->deleteFromTail();
            Sleep(1500);
            system("CLS");
            d->display();
            break;

        case 6:
            if (d->getSize() > 0)
            {
                while (true)
                {
                    cout << "Enter the index from 0 to " << d->getSize() - 1 << " to delete: ";
                    try
                    {
                        getline(cin, input);
                        index = stoi(input);
                        if (index < 0 || index > d->getSize() - 1)
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
                d->deleteFromPosition(index);
            }
            else
            {
                cout << "Array is Empty." << endl;
                Sleep(1500);
                system("CLS");
            }
            d->display();
            break;

        case 7:
            system("CLS");
            cout << " -> Size of Array is: " << d->getSize() << endl
                 << " -> Capacity of Array: " << d->getCapacity() << endl
                 << "Current Values In Array" << endl;
            d->display();
            break;

        case 8:
            while (true)
            {
                cout << "Enter New Size for Array Greater then " << d->getSize() << ": ";
                try
                {
                    getline(cin, input);
                    index = stoi(input);
                    if (index < 0 || index < d->getSize())
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 12);
                        cout << "Invalid Index" << endl;
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
            d->increaseSize(index);
            Sleep(1500);
            system("CLS");
            d->display();
            break;

        case 9:
            cout << "\n\t\tGood Bye :)\n\n\n";
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    delete[] arr;
    return 0;
}
