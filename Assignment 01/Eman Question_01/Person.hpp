#pragma once

#include <string>

class Person
{
private:
    std::string Name;
    std::string Address;
    std::string Contact;

public:
    Person(const std::string, const std::string, const std::string);
    ~Person();

    void setName(const std::string);
    void setAddress(const std::string);
    void setContact(const std::string);

    std::string getName() const;
    std::string getAddress() const;
    std::string getContact() const;

    bool is_valid(std::string, std::string);
    std::string take_input(std::string);
    Person take_input_person();

    bool operator<(const Person&) const;
    bool operator<=(const Person&) const;
    bool operator>(const Person&) const;
    bool operator==(const Person&) const;
    bool operator!=(const Person&) const;

    void Print() const;
};