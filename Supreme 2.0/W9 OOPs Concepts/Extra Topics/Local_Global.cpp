#include<iostream>
using namespace std;

int x = 10; // Global variable

void fun(){
    int x = 60; // Local variable
    cout << x << endl; // 60
    cout << ::x << endl; // 10 accessing global variable
}

int main(){
    int x = 20; // Local variable
    cout << x << endl; // 20
    cout << ::x << endl; // 10 accessing global variable
    {
        int x = 50; 
        {
            int x = 30; // Local variable
            cout << x << endl; // 30
            // There is no way to access the variable x = 20, except by removing it.
            cout << ::x << endl; // 10 accessing global variable
        }
        cout << x << endl; // 50
        cout << ::x << endl; // 10 accessing global variable
    }
    fun();
    return 0;
}