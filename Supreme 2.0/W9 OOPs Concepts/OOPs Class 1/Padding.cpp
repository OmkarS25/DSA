// Code of Class-1

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Student{
    // double a,b;
    char ab;
    string name;
    int age;
    int id;
    // bool present, absent; 
    // total size of object = sum of size of all data members
    // so total size of object = 4+4+1 = 9
    // but size of object is 12
    // this is because of padding
    // padding is done to make the size of object a multiple of 4
    // so padding = 3
    // so total size of object = 9+3 = 12
    // at last padding is done to make the size of object a multiple of 4 
    // bcz it is easy to access the data in the memory if it is a multiple of 4

    // now when I add a double data member to the class
    // total size of object = 4+4+1+8 = 17
    // but size of object is 24 and not 20
    // how did this happen?
    // padding is done to make the size of object a multiple of 8
    // so padding = 7
    // this means that padding is done on the basis of the largest data member in the class
    // but when I add string data member to the class
    // total size of object = 8+8+1+32+4+4 = 57
    // but size of object is 64
    // now the largest data member is string
    // so padding should be done on the basis of string
    // but padding is still going on the basis of double
    // this is because padding is done on the basis of the largest data member which is not user defined data type
};

int main(){
    cout<<sizeof(Student)<<endl;
    return 0;
}