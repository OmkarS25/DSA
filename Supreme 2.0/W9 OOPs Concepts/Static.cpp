#include<iostream>
using namespace std;

class abc{
public:
    static int x,y;
    int a,b;
    void print() const{
        // cout<<this->x<<" "<<this->y<<endl; // this keyword will only print the same thing.
        cout<<x<<" "<<y<<endl;
    }
    static void print_static(){
        cout<<x<<" "<<y<<endl;
        //cout<<a<<" "<<b<<endl; // Static member function can't access non-static members.
        // No instances can be passed to static member function.
        // no this pointer is passed to static member function.
        printf("I am in  static %s\n",/*__func__*/__FUNCTION__);
    }
};

int abc::x;
int abc::y;

int main(){
    abc obj1;
    obj1.x = 1;
    obj1.y = 2;
    obj1.print();
    abc obj2;
    obj2.x = 10;
    obj2.y = 20;
    obj1.print();
    obj2.print();
    // Static members can also be accessed using class name.
    abc::x = 20;
    abc::y = 30;
    // Static member function can also be accessed using class name.
    abc::print_static();
    return 0;
}