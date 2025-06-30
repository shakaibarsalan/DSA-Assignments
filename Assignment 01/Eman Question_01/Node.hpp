#pragma once

#include "Person.hpp"

class Node
{
public:
    Person data;
    Node *next;
    Node *previous;

    Node();
    Node(Person &);
};