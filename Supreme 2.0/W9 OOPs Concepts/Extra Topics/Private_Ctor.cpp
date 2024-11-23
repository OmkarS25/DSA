#include<iostream>
using namespace std;

// Yes we can have private constructor in C++.
// We can use a friend class to access the private constructor.
// This type of thing is used in Singleton design pattern.
// https://learn.microsoft.com/en-us/cpp/cpp/constructors-cpp?view=msvc-170 
// Refer this link for more details.

class Box{
    int width;

    // private ctor
    Box(int _width): width(_width){
        cout << "Constructor called" << endl;
    }
public:
    int getWidth() const {
        return width;
    }
    
    void setWidth(int _val){
        width = _val;
    }
    ~Box(){
        cout << "Destructor called" << endl;
    }
    friend class BoxFactory;
};

class BoxFactory{
    int count;
public:
    BoxFactory(): count(0){}
    Box createBox(int _width){
        count++;
        return Box(_width);
    }
    int getCount() const {
        return count;
    }
};

int main(){
    BoxFactory bfact;
    Box b = bfact.createBox(10);
    cout << "Width: " << b.getWidth() << endl;
    b.setWidth(20);
    cout << "Width: " << b.getWidth() << endl;
    return 0;
}

// // In this we can also track the number of objects created and destroyed using the factory class
// class Box{
//     int width;
//     BoxFactory* factory;

//     // private ctor
//     Box(int _width, BoxFactory* _factory): width(_width), factory(_factory){
//         cout << "Constructor called" << endl;
//     }
// public:
//     int getWidth() const {
//         return width;
//     }
    
//     void setWidth(int _val){
//         width = _val;
//     }
//     ~Box(){
//         cout << "Destructor called" << endl;
//         if (factory) {
//             factory->decreaseCount();
//         }
//     }
//     friend class BoxFactory;
// };

// class BoxFactory{
//     int count;
// public:
//     BoxFactory(): count(0){}
//     Box createBox(int _width){
//         count++;
//         return Box(_width, this);
//     }
//     int getCount() const {
//         return count;
//     }
//     void decreaseCount() {
//         count--;
//     }
// };