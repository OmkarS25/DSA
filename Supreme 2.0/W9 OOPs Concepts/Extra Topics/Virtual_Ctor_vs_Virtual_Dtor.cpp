#include<iostream>
using namespace std;

class Base
{
    public:
        Base()
        {
            cout<<"Base Constructor"<<endl;
        }
        virtual ~Base()
        {
            // You should always make base class dtor virtual for proper destruction of object.
            cout<<"Base Destructor"<<endl;
        }
};

class Derived: public Base
{
    int *a;
    public:
        Derived()
        {
            a = new int[10];
            cout<<"Derived Constructor"<<endl;
        }
        ~Derived()
        {
            delete[] a;
            cout<<"Derived Destructor"<<endl;
        }
};

int main()
{
    Base *b = new Derived();
    delete b;
    return 0;
}