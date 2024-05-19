// Print all digits of an integer (Book-1,Pg-10)

#include<iostream>
using namespace std;

void printNumber(int num){
    while(num){
        cout<<"Digits :"<<num%10<<endl;
        num /= 10;
    }
}

int main(){
    int num = 0;
    cout<<"Enter the number : ";
    cin>>num;
    printNumber(num);
    return 0;
}