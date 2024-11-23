#include<iostream>
using namespace std;

//---> Const in C++

int main1(){
    // 1. Normal Const Variable
    //const int a = 5; // This is a constant value
    // a = 10; This is not allowed as it is a not modifiable lvalue
    // So, initialization can be done but cannot be modified.

    // If you want to change the value of the const variable
    // then you can use a pointer method but it only works in old C based compilers
    // It is not recommended to use this method**
    // int *ptr = &a;
    // *ptr = 10;
    //cout<<a<<endl;

    // Random Lesson
    // int *a = new int;
    // *a = 10;
    // cout<<*a<<endl;
    // delete a; // Delete this right now or else it will be a memory leak
    // int b = 5;
    // a = &b;
    // cout<<*a<<endl;

    // 2.Const with Pointers
    // CONST Data, NON-CONST Pointer.
    // const int *a = new int(5); 
    // int const *a = new int(5); // same as above line, just another way of writing it.
    // *a = 20; // Cannot change the content of the pointer.
    // int b = 5;
    // a = &b; // Can change the address in the pointer.

    // 3.NON-CONST Data, CONST Pointer.
    // int * const a = new int(5);
    // *a = 20; // Allowed hai
    // int b = 5;
    // a = &b; // Not allowed as the pointer is constant.

    // 4. CONST Data, CONST Pointer.
    // const int * const a = new int(5);
    // *a = 20; // Not allowed as the data is constant.
    // int b = 5;
    // a = &b; // Not allowed as the pointer is constant.

    return 0;
}

class abc{
    int x,*y,z;
    mutable int a; // This is a mutable variable, it can be changed in a const function.

public:
    abc(){
        x=0;
        y = new int(0);
    }
    abc(int _x, int _y, int _z, int _a = 0 /*This is know as default argument.*/){
        x = _x;
        y = new int(_y);
        z = _z;
        a = _a;
    }
//---> Initialization List
    abc(int _x, int _y, int _z):x(_x),y(new int(_y)),z(_z),a(0){
        // This is called initialization list
        // It is used to initialize the member variables of the class.
        // It is used to initialize the const variables of the class.
        // It is used to initialize the reference variables of the class.
        // It is used to initialize the variables of the class which are objects of other classes.
    }
    int getX() const{ 
        // you can't change any member variable in this function
        return x;
    }
    int getZ(){
        return z;
    }
    int getY() const{ 
        // you can't change any member variable in this function
        return *y;
    }
    void setX(int _val){ 
        // you don't want to make this type of fuction const
        // as you are changing the value of x
        x = _val;
    }
    void setY(int _val){
        // you don't want to make this type of fuction const
        // as you are changing the value of y
        *y = _val;
    }

    int writeA() const{
        a = 10; // This should have give an error as the function is const
        // but as A is a mutable variable, it can even be changed in a const function.
        // This is not recommended to use but can be used for degugging purposes.
        return a;
    }

    // diff bw int const writeA() and int writeA() const is that
    // in int const writeA() you can't change the value of width
    // but in int writeA() const you can change the value of width
    // as the function is const.

    ~abc(){
        delete y;
    }
};

void printAll(const abc& obj){
    cout<<obj.getX()<<" "<<obj.getY()<<" ";
    // cout<<obj.getZ(); // This will give an error as getZ is not a const function
    // And this printAll fun only accepts const obj of class abc.
}

int main2(){
    abc obj(10, 12, 15, 0);
    printAll(obj);
    return 0;
}

//---> MACROS in C++

#define PI 3.14159465 // This is a macro which will replace PI with 3.14159465
#define MAXX(x,y) (x > y ? x : y) // This is a macro which will replace MAXX(x,y) with (x > y ? x : y)

float circleArea(float r){
    return PI*r*r;
}
float circlePerimeter(float r){
    return 2*PI*r;
}
int fun(){
    int a = 10;
    int b = 20;
    int c = MAXX(a,b);
}

int main(){
    cout<<"Area of Circle: "<<circleArea(65.4)<<endl;
    return 0;
}