#pragma once

#include <string>

class Node;

class LinkedList
{
private:
    Node *head;
    int length;

public:
    LinkedList();
    ~LinkedList();

    void Add_Node();
    void Add_Node(Person &);
    
    void putInOrder(Node *&);
    void Remove_Node(int);
    void Remove_Person(std::string);
    void Edit_Person(std::string); // via name
    void Edit_Person(Node *); // via address
    int Find_Person(const std::string) const;

    void Print(std::string) const;
    void Print(int) const;
    void Print(Node *) const;
    void Print_Names() const;
    void Print_List() const;
    void Read_Book() const;
};