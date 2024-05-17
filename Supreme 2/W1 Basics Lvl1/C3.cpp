// THis is extra class by Lakshya bhaiya on Decimal and Binary.

#include<iostream>
#include<cmath>
using namespace std;

int decimaltobinarymethod1(int n){
    // Division Mehtod.
    int binaryno = 0;
    int i = 0;
    while(n>0){
        int bit = n%2;
        binaryno = bit*pow(10, i++) + binaryno;
        n = n/2;
    }
    return binaryno;
}

int decimaltobinarymethod2(int n){
    // Bitwise Mehtod. 
    int binaryno = 0;
    int i = 0;
    while(n>0){
        int bit = (n & 1);
        binaryno = bit*pow(10, i++) + binaryno;
        n = n>>1;
    }
    return binaryno;
}

int binarytodecimal(int n){
    int decimal = 0;
    int i = 0;
    while(n){
        int bit = n % 10;
        decimal = decimal + bit * pow(2,i++);
        n/=10;
    }
    return decimal;
}



int main(){
    // int n;
    // cin>>n;
    // int binary = decimaltobinarymethod1(n);
    // cout<<binary<<endl;
    
    // int n;
    // cin>>n;
    // int binary = decimaltobinarymethod2(n);
    // cout<<binary<<endl;

    int binaryno;
    cin>>binaryno;
    cout<<binarytodecimal(binaryno);
    return 0;
}