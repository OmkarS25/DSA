/**
 * @brief In this class we will learn about copy ctor, dtor 
 * and why copy ctor parameter should be const and address 
 * of srcobj needs to be passed
 * @date 2024-09-03
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
private:
    string gf;

public:
    int id;
    int age;
    bool present;
    string name;
    int nos;
    int *v;

    // ctor: Default ctor: assigns garbage value
    // no khokhla student
    Student()
    {
        cout << "Student ctor called" << endl;
    }

    // paremeterized constructor or ctor
    Student(int id, int age, bool present, string name, int nos, string gf)
    {
        this->id = id;
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;
        this->gf = gf;
        this->v = new int(10);
        cout << "Student paremeterized ctor called" << endl;
    }

    Student(int id, int age, bool present, string name, int nos)
    {
        this->id = id;
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;
        cout << "Student paremeterized ctor w/o gf called" << endl;
    }

    // Another way to write the ctor
    Student(int m_id, int m_agf, bool m_present, string m_name) : id(m_id), age(m_agf), present(m_present), name(m_name)
    {
        cout << "Student paremeterized ctor which is written in a different way of initalizing." << endl;
    }

    // copy constructor or ctor
    Student(const Student &srcobj)
    {
        cout << "Student copy ctor called" << endl;
        this->name = srcobj.name;
        this->age = srcobj.age;
        this->gf = srcobj.gf;
        this->nos = srcobj.nos;
        this->present = srcobj.present;
        this->id = srcobj.id;
    }

    // getter / setter
    string getGfName()
    {
        return gf;
        // return this->gf;
    }

    void setGfName(string gf)
    {
        // authentication like dost, mummy, papa, yourself.
        // Ya toh gf ka name female hi hona chaiye.
        this->gf = gf;
    }

    void study()
    {
        cout << "studying" << endl;
    }
    void sleep()
    {
        cout << "sleeping" << endl;
    }
    void bunk()
    {
        cout << "bunking" << endl;
    }

    ~Student()
    {
        cout << "Student dtor called" << endl;
        delete v;
    }

private:
    void gfchatting()
    {
        cout << "Chatting" << endl;
    }

    void cheating()
    {
        cout << "Cheating" << endl;
    }
};

int main()
{
    // copy ctor
    // Student s1(1, 12, 1, "Chota Bheem", 1, "Chutki");
    // Student s2 = s1;
    // Student s2(s1);

    // Student s2 = s1;

    // cout << s1.name << endl;
    // cout << s2.name << endl;

    Student s1(1, 12, 1, "Chota Bheem", 1);
    cout << s1.name << endl;
    cout << s1.getGfName() << endl;

    s1.setGfName("Indumati");

    cout << s1.getGfName() << endl;

    return 0;
    
}