#include <iostream>
using namespace std;

class A{
    int x;
public:
    A(int _val) : x(_val) {}

    int getX() const { return x; }
    int setX(int _val) { x = _val; }

    // Rather than making this confusion using friend keyword,
    // just make a function that can pass the value to the other class/function.
    void print() const {
        cout << x << endl;
    }

    friend class B; // This is used for making a class friend.
    friend void print(const A &); // This is used for making a fuction friend.
};

class B{
public:
    void print(const A &obj){
        // cout<<obj.getX()<<endl;
        cout << obj.x << endl;
    }
};

void print(const A &obj){
    // cout<<obj.getX()<<endl;
    cout<<obj.x<<endl;
}

int main(){
    A a(5);
    B b;
    b.print(a);
    return 0;
}