#include <iostream>
using namespace std;

class Person
{
public:
    int age;
    string name;
    string address;

    void print()
    {
        cout << "Name: " << name << endl;
    }
};

struct SPerson
{
    int age;
    string name;
    string address;

    SPerson(int age, string name, string address)
    {
        this->name = name;
        this->age = age;
        this->address = address;
    }

    void print()
    {
        cout << "Name: " << name << endl;
    }

};



int main()
{
    SPerson *sp1 = new SPerson(25, "John", "123 Main St");
    SPerson *sp2 = new SPerson(30, "Jane", "456 Elm St");

    sp1->print();
    sp2->print();

    sp1 = sp2;
    sp1->print();
    sp1->name = "Bob";
    sp1->print();
    sp2->print();

}