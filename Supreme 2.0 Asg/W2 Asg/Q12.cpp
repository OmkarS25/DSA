// Given Number is Even or Odd (Book-1,Pg-8)

#include<iostream>
using namespace std;

bool checkEven(int n){
    // Normal Method
    if(n%2 == 0) 
        return true; 
    else 
        return false;
    // Bitwise Method
    // if((n&1) == 0)
    //     return true;
    // else 
    //     return false;
}
int main(){
    int n = 3;
    bool isEven = checkEven(n);
    if(isEven){
        cout<<"The number "<<n<<" is even."; 
    }
    else{
        cout<<"The number "<<n<<" is odd."; 
    }
    return 0;
}