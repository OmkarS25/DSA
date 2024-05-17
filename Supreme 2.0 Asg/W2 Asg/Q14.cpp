// Check the given number is prime or not. (Book-1,Pg-8)

#include<iostream>
using namespace std;

bool checkPrime(int n){
    if(n==0 || n==1) return false;
    for(int i=2; i<=n/2/*also can use sqrt(n)*/; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main(){
    int n1 = 17, n2 = 12;
    cout<<"Is "<<n1<<" prime :"<<boolalpha<<(checkPrime(n1))<<endl;
    cout<<"Is "<<n2<<" prime :"<<boolalpha<<(checkPrime(n2))<<endl;
    // "boolalpha" is used to print true or false else it prints 0 or 1.
    return 0;
}