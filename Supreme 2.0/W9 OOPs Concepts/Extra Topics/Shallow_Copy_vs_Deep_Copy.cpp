#include<iostream>
using namespace std;

class abc{
public:
    int x, *y;

    abc(int a, int b) : x(a), y(new int(b)) {}

    // default dumb copy constructor : it does SHALLOW COPY
    // abc(const abc &obj){
    //     x = obj.x;
    //     y = obj.y;
    // }

    // SMART deep copy constructor
    abc(const abc &obj){
        x = obj.x;
        y = new int(*obj.y);
    }

    void print() const{
        printf("X: %d\nPTR Y:%p\nContent of Y (*y):%d\n\n", x, y, *y);
    }

    ~abc(){
        delete y;
    }
};

int main(){
    abc a(1, 2);
    cout << "Printing A\n";
    a.print();

    // abc b(a);
    abc b = a;
    cout << "Printing B\n";
    b.print();

    *b.y = 20;
    cout << "Printing B after changing *y\n";
    b.print(); // only b should be changed
    cout << "Printing A after changing B's *y\n";
    a.print(); // a should not be changed
    return 0;
}