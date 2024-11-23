#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    void walk()
    {
        cout << "Walking..." << endl;
    }
};

class Teacher : virtual public Person
{
public:
    void teach()
    {
        cout << "Teaching..." << endl;
    }
};

class Researcher : virtual public Person
{
public:
    void research()
    {
        cout << "Researching..." << endl;
    }
};

// multiple inheritence
class Professor : public Teacher, public Researcher
{
public:
    void bore()
    {
        cout << "Boring...";
    }
};

int main()
{
    Professor p;

    // Diamond Problem
    // p.walk(); // Ambiguity because walk is 
    // present in both teacher and researcher.
    // Solution 1: Scope Resolution
    // p.Teacher::walk();
    // p.Researcher::walk();

    // Solution 2: Virtual
    p.walk();

    // What if we directly inherit person in professor
    // then we will have to add in virtually in professor because
    // we have already inherited person in teacher and researcher and 
    // it will become ambiguous/ extra copy of professor walk function 
    // creating the confusion.

    return 0;
}