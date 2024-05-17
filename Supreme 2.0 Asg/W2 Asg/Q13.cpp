// Find the Factorial (Book-1,Pg-8)

#include<iostream>
using namespace std;


int main(){
    int n = 5; // Max till 65.
    // For large no.s we have to use strings to calculate.
    unsigned long long int fact =1;
    for (int i = 1; i <=n; i++)
    {
        fact = fact * i;
    }
    cout<<"Factorial :"<<fact;
    return 0;
}