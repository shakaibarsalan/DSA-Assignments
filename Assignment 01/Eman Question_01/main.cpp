#include <iostream>
#include <windows.h>

#include "Person.hpp"
#include "Node.hpp"
#include "LinkedList.hpp"

int take_input_int(int from = 0, int to = 0)
{
    std::string input;
    int to_return;
    bool valid = false;

    while (!valid)
    {
        valid = true;

        std::cout << "Enter integer input: ";
        std::getline(std::cin, input, '\n');

        if (input.empty())
        {
            std::cout << "Invlid!\n";
            valid = false;
        }

        for (int i = 0; i < input.length(); i++)
        {
            if (!isdigit(input[i]))
            {
                valid = false;
            }
        }

        if (valid && from != to) // meaning if args were given
        {
            to_return = stoi(input);
            if (to_return < from || to_return > to)
                valid = false;
        }
    }

    return (stoi(input));
}

char take_input_char(char a, char b, char c)
{
    char input;
    do
    {
        std::cout << "\nEnter character input: ";
        std::cin >> input;

        if (input != a && input != b && input != c)
        {
            std::cout << "Invalid!\n";
        }

    } while (input != a && input != b && input != c);

    return input;
}

Person ::Person(const std::string name = "", const std::string address = "", const std::string contact = "")
{
    Name = name;
    Address = address;
    Contact = contact;
}

Person ::~Person() {}

void Person::setName(const std::string name)
{
    Name = name;
}
void Person::setAddress(const std::string address)
{
    Address = address;
}
void Person::setContact(const std::string contact)
{
    Contact = contact;
}

std::string Person::getName() const
{
    return Name;
}
std::string Person::getAddress() const
{
    return Address;
}
std::string Person::getContact() const
{
    return Contact;
}

void to_upper(std::string &st)
{
    for (int i = 0; i < st.length(); i++)
    {
        st[i] = std::toupper(st[i]);
    }
}

bool Person ::operator<(const Person &other) const
{

    std::string temp_this = this->Name;
    std::string temp_other = other.Name;

    to_upper(temp_this);
    to_upper(temp_other);

    if (temp_this < temp_other)
    {
        return true;
    }
    return false;
}

bool Person ::operator<=(const Person &other) const
{

    std::string temp_this = this->Name;
    std::string temp_other = other.Name;

    to_upper(temp_this);
    to_upper(temp_other);
    std::cout << "<Comparing: " << temp_this << " and " << temp_other << std::endl;

    if (temp_this <= temp_other)
    {
        return true;
    }
    return false;
}
bool Person ::operator>(const Person &other) const
{

    std::string temp_this = this->Name;
    std::string temp_other = other.Name;

    to_upper(temp_this);
    to_upper(temp_other);

    if (temp_this > temp_other)
    {
        return true;
    }
    return false;
}
bool Person ::operator==(const Person &other) const
{

    std::string temp_this = this->Name;
    std::string temp_other = other.Name;

    to_upper(temp_this);
    to_upper(temp_other);

    if (temp_this == temp_other)
    {
        return true;
    }
    return false;
}
bool Person ::operator!=(const Person &other) const
{

    std::string temp_this = this->Name;
    std::string temp_other = other.Name;

    to_upper(temp_this);
    to_upper(temp_other);

    if (temp_this != temp_other)
    {
        return true;
    }
    return false;
}

void Person::Print() const
{
    std::cout << "\n ==== PERSON INFORMATION ====\n";
    std::cout << "Name: " << Name << '\n';
    std::cout << "Address: " << Address << '\n';
    std::cout << "Contact: " << Contact << '\n';
    std::cout << "_______________________________\n";
}

Person Person::take_input_person()
{
    std::string name, address, contact;

    std::cout << "\n === Input Person Details ===\n";

    name = this->take_input("name");

    std::cout << "\nEnter Address: ";
    std::getline(std::cin, address, '\n');

    contact = this->take_input("contact");

    Person temp(name, address, contact);
    return temp;
}

bool Person::is_valid(std::string to_check, std::string type)
{
    if (type == "contact")
    {
        if (to_check.length() != 10)
        {
            std::cout << "Invalid Contact (length)\n";
            return false;
        }
        if (to_check[0] != '3')
        {
            std::cout << "contact first is: " << to_check[0] << std::endl;
            std::cout << "Invalid Contact (format)\n";
            return false;
        }
        for (int i = 0; i < to_check.length(); i++)
        {
            if (!std::isdigit(to_check[i]))
            {
                std::cout << "Invalid Contact (char: " << i << ")\n";
                return false;
            }
        }
        return true;
    }
    else if (type == "name")
    {
        for (int i = 0; i < to_check.length(); i++)
        {
            if (!(std::isalpha(to_check[i]) || to_check[i] == ' '))
            {
                std::cout << "Name can only contain alphabets\n";
                return false;
            }
        }

        int spaces_in_check = 0;
        for (int i = 0; i < to_check.length(); i++)
        {
            if (to_check[i] == ' ')
                spaces_in_check++;
        }
        if (spaces_in_check >= to_check.length())
            return false;
        else
            return true;
    }
}

std::string Person::take_input(std::string type)
{
    if (type == "contact")
    {
        std::string contact;
        bool contact_is_valid = false;

        while (!contact_is_valid)
        {
            std::cout << "\nEnter Contact Number (+92 format): +92";
            std::getline(std::cin, contact, '\n');

            if (is_valid(contact, "contact"))
                contact_is_valid = true;
        }

        return contact;
    }

    else if (type == "name")
    {
        std::string name;
        bool name_is_valid = false;

        while (!name_is_valid)
        {
            std::cout << "\nEnter Name: ";
            std::getline(std::cin, name, '\n');

            if (is_valid(name, "name"))
                name_is_valid = true;
        }

        return name;
    }
}

Node ::Node(Person &person)
{
    data = person;
    next = nullptr;
    previous = nullptr;
}

Node ::Node()
{
    data = Person("", "", "");
    next = nullptr;
    previous = nullptr;
}

LinkedList ::LinkedList()
{
    head = NULL;
    length = 0;
}

LinkedList ::~LinkedList()
{
    Node *current = head;
    Node *to_del;

    while (current != nullptr)
    {
        to_del = current;
        current = current->next;
        delete to_del;
    }
}

void LinkedList ::Add_Node()
{
    Person new_person = new_person.take_input_person();

    Add_Node(new_person);
}

void LinkedList ::Add_Node(Person &new_person)
{
    std::cout << "Add node" << new_person.getName() << "\n";
    Node *to_insert = new Node(new_person);

    if (!head)
    {
        head = to_insert;
        length = 1;
        std::cout << "Head Created\n";
    }
    else
    {
        std::cout << "Pur in order aboyt to cll\n";
        putInOrder(to_insert);

        length++;
        std::cout << "New Person added\n";
    }
}
void LinkedList::putInOrder(Node *&to_put)
{

    Node *current = head;

    if (!current)
    {
        head = to_put;
        length = 1;
        return;
    }
    else if (to_put->data < current->data)
    {
        to_put->next = head;
        head->previous = to_put;
        head = to_put;
    }
    else
    {
        while (current->next && current->next->data < to_put->data)
        {
            current = current->next;
        }
        to_put->next = current->next;
        to_put->previous = current;
        current->next = to_put;

        if (to_put->next)
        {
            to_put->next->previous = to_put;
        }
    }
}

void LinkedList::Remove_Node(int pos = 0)
{
    if (pos == 0)
    {
        std::cout << "Enter the Position Number to Delete (1-" << length << ")\n";
        pos = take_input_int(1, length);
    }

    if (!head)
    {
        std::cout << "List Doesnt Exist\n";
        return;
    }

    if (pos == 1)
    {
        if (head->next == nullptr)
        {
            delete head;
            length = 0;
        }

        else
        {
            head = head->next;

            delete (head->previous);
            length--;
            head->previous = nullptr;
        }

        return;
    }
    Node *current = head;
    for (int i = 0; i < pos - 1; i++)
    {
        current = current->next;
    }

    if (!(current->next)) // if current is last node
    {
        current->previous->next = nullptr;
        std::cout << "lasr is deleting\n";
        std::cout << current->data.getName() << current->previous->data.getName() << "\n";
    }
    else
    {
        current->previous->next = current->next;
        current->next->previous = current->previous;
    }

    delete current;
    length--;
    return;
}

void LinkedList::Remove_Person(std::string to_remove = "")
{
    if (to_remove == "")
    {
        std::cout << "Enter Person's Name to Remove (case sensitive): ";
        std::getline(std::cin, to_remove, '\n');
    }

    int pos = 1;
    Node *current = head;

    while (current)
    {

        if (current->data.getName() == to_remove)
        {
            std::cout << "Name found\n";
            Remove_Node(pos);
            std::cout << "Removed Successfully\n";
            return;
        }

        current = current->next;
        pos++;
    }
    std::cout << "Person (" << to_remove << ") not Found in the List\n";
    return;
}

void LinkedList::Edit_Person(Node *to_edit)
{
    if (to_edit == nullptr)
    {
        std::cout << "Doesn't Exist\n";
        return;
    }
    else
    {
        Node *updated_node = new Node;
        updated_node->data = updated_node->data.take_input_person();

        int pos = Find_Person(to_edit->data.getName());
        Remove_Node(pos);

        putInOrder(updated_node);
        return;
    }
}

void LinkedList::Edit_Person(std::string to_edit = "")
{
    if (to_edit == "")
    {
        std::cout << "Enter Name to Edit (case sensitive): ";
        std::getline(std::cin, to_edit, '\n');
    }

    Node *current = head;
    while (current)
    {
        if (current->data.getName() == to_edit)
        {
            Edit_Person(current);
            return;
        }
        current = current->next;
    }
    std::cout << to_edit << " not found in List\n";
}

int LinkedList::Find_Person(std::string to_find = "") const
{
    if (to_find == "")
    {
        std::cout << "Enter Name to Search (case sensitive): ";
        std::getline(std::cin, to_find, '\n');
    }

    Node *current = head;
    int count = 1;

    while (current)
    {
        if (current->data.getName() == to_find)
        {
            std::cout << "Found at Position: " << count << '\n';
            return count;
        }
        count++;
        current = current->next;
    }

    std::cout << "Not found\n";
    return -1;
}

void LinkedList::Print(std::string to_print) const
{
    int person_pos = Find_Person(to_print);
    if (person_pos > 0)
        Print(person_pos);
}

void LinkedList::Print(int person_pos = 0) const
{
    if (person_pos == 0)
        person_pos = take_input_int(1, length);

    Node *current = head;
    for (int i = 0; i < person_pos - 1; i++)
    {
        current = current->next;
    }
    if (person_pos > 0)
        ;
    current->data.Print();
}

void LinkedList::Print(Node *to_print) const
{
    to_print->data.Print();
}

void LinkedList ::Print_Names() const
{
    std::cout << "\n === All Names in List ====\n";
    Node *current = head;

    while (current)
    {

        std::cout << current->data.getName() << '\n';

        // std::cout << "Ppap:               " << current->data.getName() << '\n';
        // if (current->previous)
        //     std::cout << "Pre:" << current->previous->data.getName() << std::endl;
        // if (current->next)
        //     std::cout << "next: " << current->next->data.getName() << std::endl;
        current = current->next;
    }
}

void LinkedList ::Print_List() const
{
    Node *current = head;

    while (current)
    {
        current->data.Print();
        current = current->next;
    }
}

void LinkedList ::Read_Book() const
{
    if (!head)
    {
        std::cout << "Empty Book\n";
        return;
    }

    char move;

    int person_number = 1;
    Node *current = head;

    while (true)
    {
        system("CLS");
        std::cout << "Person Number: " << person_number << '\n';
        Print(current);

        do
        {

            std::cout << "Next, Previous or Exit (n, p, 0): ";
            move = take_input_char('n', 'p', '0');
            if (move == 'p')
            {
                if (!current->previous)
                    std::cout << "No Address Before this\n\n";
                else
                {
                    current = current->previous;
                    person_number--;
                    break;
                }
            }
            else if (move == 'n')
            {
                if (!current->next)
                    std::cout << "No Address After this\n\n";
                else
                {
                    current = current->next;
                    person_number++;
                    break;
                }
            }
            else if (move == '0')
            {
                std::cin.ignore();
                return;
            }

        } while (true);
    }
}

void User_Manual(LinkedList &MyList)
{
    int choice;
    std::string cont;
    std::string mousoof;

    system("CLS");
    std::cout << " ==== ADDRESS BOOK SYSTEM ====\n\n";
    std::cout << "1. New Person Entry\n";
    std::cout << "2. Find Person\n";
    std::cout << "3. Edit Person\n";
    std::cout << "4. Remove Person\n";
    std::cout << "5. Print All Names\n";
    std::cout << "6. Start Reading Address Book\n";
    std::cout << "0. Exit\n\n";

    choice = take_input_int(0, 6);

    switch (choice)
    {
    case 1:
    {
        MyList.Add_Node();
        MyList.Print_Names();

        std::cout << "\nPress any Key to Continue";
        std::cin.get();

        break;
    }
    case 2:
    {
        MyList.Print_Names();
        
        std::cout << "\nEnter Person's Name to Find: ";
        std::getline(std::cin, mousoof, '\n');

        MyList.Print(mousoof);

        std::cout << "\nPress any Key to Continue";
        std::cin.get();

        break;
    }
    case 3:
    {
        MyList.Print_Names();
        std::cout << "\nEnter Person's Name to Edit: ";
        std::getline(std::cin, mousoof, '\n');

        MyList.Edit_Person(mousoof);

        break;
    }
    case 4:
    {
        MyList.Print_Names();
        std::cout << "\nEnter Person's Name to Remove: ";
        std::getline(std::cin, mousoof, '\n');

        MyList.Remove_Person(mousoof);

        MyList.Print_Names();
        std::cout << "\nPress any Key to Continue";
        std::cin.get();

        break;
    }
    case 5:
    {
        MyList.Print_Names();
        std::cout << "\nPress any Key to Continue";
        std::cin.get();

        break;
    }
    case 6:
    {
        MyList.Read_Book();
        break;
    }
    case 0:
    {
        std::cout << "\n==== GoodBye ====\n";
        return;
        break;
    }
    default:
        std::cout << "Invalid\n";
        break;
    }

    User_Manual(MyList);
}

int main()
{
    LinkedList l1;

    Person p1("aaaushra", "bb", "cc");
    Person p2("babushka", "bb", "cc");
    Person p3("azazel", "bb", "cc");

    Person *a1 = &p1;
    Person *a2 = &p2;
    Person *a3 = &p3;

    l1.Add_Node(p1);
    l1.Print_Names();

    l1.Add_Node(p2);
    l1.Print_Names();

    l1.Add_Node(p3);
    l1.Print_Names();

    User_Manual(l1);

    return 0;
}